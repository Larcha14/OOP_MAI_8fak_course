#pragma once
#include <iostream>
#include "coord.h"
#include <vector>
#include <exception>
#include <algorithm>
#include <math.h>
using namespace std;

template <Number T> 
class Figure{
    template<class U>
    friend istream& operator >>(istream& is, Figure<U> &f);
    template<class U>
    friend ostream& operator <<(ostream& os, Figure<U> &f);

    public:
        Figure();
        Figure(const int count);
        Figure(const vector<Coord<T>> &v, const int count);
        Figure(const initializer_list<Coord<T>> &l, const int count);
        Figure(const Figure<T> &jther);
        Figure(Figure<T> &&other)noexcept;

        virtual Coord<T> get_coord() const;
        
        virtual operator double() const;
        virtual int get_angles_count() const;
        virtual bool is_correct();  
        virtual void print_array()const;

        virtual bool operator ==(const Figure<T> &f) const;
        virtual Figure& operator = (const Figure<T> &f);
        virtual Figure& operator = (Figure<T> &&f);



        ~Figure() noexcept; 
               
        int _angles_count;
        int _array_size;
        vector<Coord<T>> _array;

    // private:
    //     int _angles_count;
    //     int _array_size;
    //     vector<coord> _array;
};

// bool cmp(Coord<T> a, Coord<T> b){
//     if(a.x==b.x){
//         return a.y>b.y;
//     }
//     return a.x>b.x;
// }


template <Number T> 
struct comp{
    bool operator()(const Coord<T> &a, const Coord<T> &b){
        if(a.x==b.x){
            return a.y>b.y;
        }
        return a.x>b.x;
    }
};

template <Number T> 
Figure<T>::Figure(){
    _angles_count=0;
    _array_size=1;
    _array.resize(1);
    _array[0].x=0;
    _array[0].y=0;

}

template <Number T> 
Figure<T>::Figure(const int count){
    _angles_count=count;
    _array.resize(count);
    for(int i=0;i<count;++i){
        _array[i].x=0;
        _array[i].y=0;
    }
}

template <Number T> 
Figure<T>::Figure(const vector<Coord<T>> &v, const int count){
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
            throw logic_error("Unacceptable Coord<T>inats");
        }
    }
}

template <Number T> 
Figure<T>::Figure(const initializer_list<Coord<T>> &l, const int count){
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

template <Number T> 
Figure<T>::Figure(const Figure<T> &other){
    _angles_count=other._angles_count;
    _array_size=other._array_size;
    _array.resize(_array_size);    
    for(int i=0; i<_angles_count;++i){
        _array[i]=other._array[i];
    }
}

template <Number T> 
Figure<T>::Figure(Figure<T> &&other) noexcept{
    _array_size=other._array_size;
    _angles_count=other._angles_count;
    _array=other._array;
    other._array=vector<Coord<T>>(0);
    other._array_size=0;
    other._angles_count=0;

}

template <Number T> 
int Figure<T>::get_angles_count()const{
    return _angles_count;
}

template <Number T> 
Coord<T> Figure<T>::get_coord() const{
    Coord<T> tmp;
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

template <Number T> 
Figure<T>::operator double() const{
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

template <Number T> 
bool Figure<T>::operator==(const Figure<T> &other)const{
    if(this->_angles_count==other._angles_count){
        return static_cast<double>(*this)==static_cast<double>(other);
    }
    return false;
}

template <Number T> 
Figure<T>& Figure<T>::operator=(const Figure<T> &other){
    this->_angles_count=other._angles_count;
    this->_array_size=other._array_size;
    this->_array.resize(_array_size);    
    for(int i=0; i<_angles_count;++i){
        this->_array[i]=other._array[i];
    }
    return *this;
}

template <Number T> 
Figure<T>& Figure<T>::operator=(Figure<T> &&other){
    this->_array_size=other._array_size;
    this->_angles_count=other._angles_count;
    this->_array=other._array;
    other._array=vector<Coord<T>>(0);
    other._array_size=0;
    other._angles_count=0;
    return *this;

}

template <Number T> 
bool Figure<T>::is_correct(){
    if(_angles_count<3){
        return false;
    }
    sort(_array.begin(), _array.end(), comp<T>());
    Coord<T> centre=get_coord();
    bool flag=true;
    double R=distance(centre, _array[0]);
    double c=distance(_array[0],_array[1]);
    if(c==0 or c<0.00001){
        flag=false;
        return flag;
    }
    // cout<<"R= "<<R<<" c= "<<c<<'\n';
    for(int i=0;i<_angles_count-2;++i){
        Coord<T> val_1=_array[i];
        Coord<T> val_2=_array[i+2];
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

template <Number T> 
void Figure<T>::print_array()const {
    for(int i=0;i<_angles_count;++i){
        cout<<_array[i].x<<' '<<_array[i].y<<'\n';

    }
}


template <Number T> 
Figure<T>::~Figure()noexcept{
    if(_array_size>=1){
        _array_size=0;
        vector<Coord<T>>().swap(_array);
        _angles_count=0;
    }
}

template <Number T> 
istream& operator>>(istream& is, Figure<T> &f){
    for(int i=0; i<f._angles_count;++i){
        Coord<T> tmp;
        is>>tmp.x>>tmp.y;
        f._array[i]=tmp;
    }
    return is;
}

template <Number T> 
ostream& operator<<(ostream &os, Figure<T> &f){
    for(int i=0; i<f._angles_count;++i){
        os<<"A"<<i<<" : "<<"x= "<<f._array[i].x<<" y= "<<f._array[i].y<<'\n';
    }
    return os;
}

