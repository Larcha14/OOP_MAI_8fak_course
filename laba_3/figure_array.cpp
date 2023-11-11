#include "./include/figure_array.h"
#include "./include/triangle.h"
#include "./include/octagon.h"
#include "./include/hexagon.h"

F_array::F_array(){
    _size=0;
    _capacity=K;
    _array = new Figure*[_capacity];
    
}

F_array::F_array(const initializer_list<Figure*> &l){
    _array = new Figure*[l.size()];
    _capacity=l.size();
    _size=0;
    for(Figure *f :l ){
        add_figure(f);
    }
    // _size=l.size();

} 

bool F_array::add_figure(Figure* f){
    if(_size==_capacity){
        int new_cap=_capacity*K;
        Figure** new_array= new Figure*[new_cap];
        for(int i=0; i<_size;++i){
            new_array[i]=_array[i];
        }
        _capacity=new_cap;
        delete[] _array;
        _array=new_array;

    }
    _array[_size]=f;
    _size++;
    return true;
}

Figure* F_array::get_figure(const int indx){
    if(_size>=indx and indx>0){
        return _array[indx];
    }
}

F_array::F_array( F_array &f_a){
    _size=f_a._size;
    _capacity=f_a._capacity;
    _array= new Figure*[_size];
    for(int i=0; i<_size;++i){
        this->add_figure(f_a.get_figure(i));
    }
}

F_array::F_array(F_array &&f_a)noexcept{
    _size=f_a._size;
    _capacity=f_a._capacity;
    _array=f_a._array;
    f_a._size=0;
    f_a._capacity=0;
    f_a._array=NULL;
}

bool F_array::del_figure(const int indx){
    if(_size>=indx and indx>0){
        for(int i=indx;i<_size-1;++i){
            _array[i]=_array[i+1];
        }

        _size--;
        return true;
    }
    return false;
}

double F_array::common_s() {
    double tmp=0;
    for(int i=0; i<_size;++i){
        tmp+=double(*_array[i]);
    }
    return tmp;
}

void F_array::print_s(){
    for(int i=0;i<_size;++i){
        cout<<"Figure"<<i<<": n="<<(*_array[i])._angles_count<<" S="<< double(*_array[i])<<'\n';
    }
}

void F_array::print_geom_centre(){
    for(int i=0; i<_size;++i){
        coord tmp;
        tmp=(*_array[i]).get_coord();
        cout<<"Geom.centre Figure"<<i<<": x="<<tmp.x<<" y="<<tmp.y<<'\n';
    }
}

F_array::~F_array(){
    if(_size>0){
        delete[] _array;
        _capacity=0;
        _size=0;
        _array=NULL;
    }
}


int F_array::get_size(){
    return this->_size;
}
