#include "./include/figure.h"


Figure::Figure(){
    _angles_count=0;
    _array_size=1;
    _array.resize(1);
    _array[0].x=0;
    _array[0].y=0;

}

Figure::Figure(const int count){
    _angles_count=count;
    _array.resize(count);
    for(int i=0;i<count;++i){
        _array[i].x=0;
        _array[i].y=0;
    }
}

Figure::Figure(const vector<coord> &v, const int count){
    if(v.size()!=count){
        throw logic_error("Uncorrect input");
    } else{
                // cout<<"hui1";
        _angles_count=count;
        _array.resize(count);
        _array_size=count;
        for(int i=0; i<count;++i){
            _array[i]=v[i];
        }
        // sort(_array.begin(), _array.end(), cmp);
        if(!is_correct()){
            // throw logic_error("Unacceptable coordinats");
        }
    }
}

Figure::Figure(const initializer_list<coord> &l, const int count){
    if(l.size()!=count){ 
        throw logic_error("Uncorrect input");
    } else{
        _angles_count=count;
        _array.resize(count);
        _array_size=count;
        int i=0;
        for(auto &c :l){
            _array[i]=c;
            i++;
        }
        if(!is_correct()){
            throw logic_error("Unacceptable coordinats");
        }

    }
}

Figure::Figure(const Figure &other){
    _angles_count=other._angles_count;
    _array_size=other._array_size;
    _array.resize(_array_size);    
    for(int i=0; i<_angles_count;++i){
        _array[i]=other._array[i];
    }
}

Figure::Figure(Figure &&other) noexcept{
    _array_size=other._array_size;
    _angles_count=other._angles_count;
    _array=other._array;
    other._array=vector<coord>(0);
    other._array_size=0;
    other._angles_count=0;

}

int Figure::get_angles_count()const{
    return _angles_count;
}

coord Figure::get_coord() const{
    coord tmp;
    tmp.x=0;
    tmp.y=0;
    for(int i=0; i<_angles_count;++i){
        tmp.x+=_array[i].x;
        tmp.y+=_array[i].y;
    }
    tmp.x=tmp.x/_angles_count;
    tmp.y=tmp.y/_angles_count;
    return tmp;

}

Figure::operator double() const{
    double s=0, s2=0;
    double tmp=0, tmp2=0;


    //case 1: point 1-2-4-6...-5-3-1
    s+=_array[0].x*_array[1].y;
    tmp+=_array[0].y*_array[1].x;
    // cout<<"s= "<<s<<"  tmp= "<<tmp<<'\n';


    for(int i=1;i<_angles_count-2;i+=2){
        s+=_array[i].x*_array[i+2].y;
        tmp+=_array[i].y*_array[i+2].x;
    }
    // cout<<"s= "<<s<<"  tmp= "<<tmp<<'\n';
    s+=_array[_angles_count-1].x*_array[_angles_count-2].y;
    tmp+=_array[_angles_count-1].y*_array[_angles_count-2].x;
        // cout<<"s= "<<s<<"  tmp= "<<tmp<<'\n';
    for(int i=0;i<_angles_count-2;i+=2){
        s+=_array[i].x*_array[i+2].y;
        tmp+=_array[i].y*_array[i+2].x;
    }

    //case2: 1-3-5-...-6-4-2-1
    s2+=_array[1].x*_array[0].y;
    tmp2+=_array[1].y*_array[0].x;
    for(int i=0;i<_angles_count-2;i+=2){
        s2+=_array[i].x*_array[i+2].y;
        tmp2+=_array[i].y*_array[i+2].x;
    }
    s2+=_array[_angles_count-2].x*_array[_angles_count-1].y;
    tmp2+=_array[_angles_count-2].y*_array[_angles_count-1].x;
    for(int i=1;i<_angles_count-2; i+=2){
        s2+=_array[i+1].x*_array[i].y;
        tmp2+=_array[i+1].y*_array[i].x;
    }
        // cout<<"s= "<<s<<"  tmp= "<<tmp<<'\n';

    // s+=_array[_angles_count-1].x*_array[0].y;
    // tmp+=_array[_angles_count-1].y*_array[0].x;
    // cout<<"s= "<<s<<" s2= "<<s2<<'\n';
    // cout<<"tmp= "<<tmp<<" tmp2= "<<tmp2<<'\n';
    s=(s-tmp)/2;
    s2=(s2-tmp2)/2;
    // cout<<"s= "<<s<<" s2= "<<s2<<'\n';
    // cout<<"tmp= "<<tmp<<" tmp2= "<<tmp2<<'\n';
    if(s2<0){
        s2=s2*(-1);
    } 
    if(s<0){ 
        s=s*(-1);
    }
    double answ=max(s, s2);
    return answ;
}

bool Figure::operator==(const Figure &other)const{
    if(this->_angles_count==other._angles_count){
        return static_cast<double>(*this)==static_cast<double>(other);
    }
    return false;
}

Figure& Figure::operator=(const Figure &other){
    this->_angles_count=other._angles_count;
    this->_array_size=other._array_size;
    this->_array.resize(_array_size);    
    for(int i=0; i<_angles_count;++i){
        this->_array[i]=other._array[i];
    }
    return *this;
}

Figure& Figure::operator=(Figure &&other){
    this->_array_size=other._array_size;
    this->_angles_count=other._angles_count;
    this->_array=other._array;
    other._array=vector<coord>(0);
    other._array_size=0;
    other._angles_count=0;
    return *this;

}


bool Figure::is_correct(){
    if(_angles_count<3){
        return false;
    }
    sort(_array.begin(), _array.end(), cmp);
    coord centre=get_coord();
    bool flag=true;
    double R=distance(centre, _array[0]);
    double c=distance(_array[0],_array[1]);
    if(c==0 or c<0.00001){
        flag=false;
        return flag;
    }
    // cout<<"R= "<<R<<" c= "<<c<<'\n';
    for(int i=0;i<_angles_count-2;++i){
        coord val_1=_array[i];
        coord val_2=_array[i+2];
        double c1=distance(val_1, val_2);
        // double r1=distance(centre, val_1);
        double r2=distance(centre, val_2);
        if(!double_cmp(r2, R) or !double_cmp(c1,c)){
            // cout<<" r2= "<<r2<<" c1= "<<c;
            flag=false;
            return flag;
        }
        
    }
    double r=distance(centre, _array[_angles_count-1]);
    double c1=distance(_array[_angles_count-1], _array[_angles_count-2]);
    if(!double_cmp(r, R) or !double_cmp(c1,c)){
            // cout<<"r= "<<r<<" c1= "<<c;
            flag=false;
            return flag;
    }
    // cout<<centre.x<<' '<<centre.y<<'\n'<<'\n';
    // cout<<d<<'\n';

    // for(int i=1; i<_angles_count;++i){
    //     double cur_d=distance()
    // }
    return flag;
}

void Figure::print_array()const {
    for(int i=0;i<_angles_count;++i){
        cout<<_array[i].x<<' '<<_array[i].y<<'\n';

    }
}


Figure::~Figure()noexcept{
    if(_array_size>=1){
        _array_size=0;
        vector<coord>().swap(_array);
        _angles_count=0;
    }
}

istream& operator>>(istream& is, Figure &f){
    for(int i=0; i<f._angles_count;++i){
        coord tmp;
        is>>tmp.x>>tmp.y;
        f._array[i]=tmp;
    }
    return is;
}

ostream& operator<<(ostream &os, Figure &f){
    for(int i=0; i<f._angles_count;++i){
        os<<"A"<<i<<" : "<<"x= "<<f._array[i].x<<" y= "<<f._array[i].y<<'\n';
    }
    return os;
}

// int main(){
//     vector<coord> c(6);
//     c[0].x=2;
//     c[0].y=0;
//         c[1].x=1.39;
//     c[1].y=1.28;
//         c[2].x=-0.02;
//     c[2].y=1.4;
//         c[3].x=-0.83;
//     c[3].y=0.23;

//         c[4].x=-0.22;
//     c[4].y=-1.05;
//         c[5].x=1.19;
//     c[5].y=-1.16;
//     // for(int i=0; i<4;++i){
//     //     c[i].x=i%2;
//     //     c[i].y=1-i%2;
//     // }
//     Figure f1(c,6);
//     f1.print_array();
//     // double r1=0.101112;
//     // double r2=0.1012341;
//     // cout<<'\n'<<double_cmp(r1,r2);
    
// }