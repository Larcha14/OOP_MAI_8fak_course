#pragma once
#include <memory>
#include "figure.h"
using namespace std;

#define K 2

template <class T> 
class F_array {
    public:
    F_array();
    F_array(const initializer_list<T> &l);
    F_array( F_array<T> &f_a);
    F_array(F_array<T> &&f_a)noexcept;

    double common_s();
    bool add_figure(T f);
    T get_figure(const int indx);
    bool del_figure(const int indx);
    void print_s();
    void print_geom_centre();
    int get_size();

    ~F_array();
    private:
        int _size;
        int _capacity;
        shared_ptr<T[]> _array;
};   

template <class T> 
F_array<T>::F_array(){
    _size=0;
    _capacity=K;
    _array=shared_ptr<T[]>(new T[_capacity]);
    // _array= make_shared<T[]>(_capacity);
    // _array = new Figure*[_capacity];
    
}

template <class T> 
F_array<T>::F_array(const initializer_list<T> &l){
    // _array = new Figure*[l.size()];
    _array=shared_ptr<T[]>(new T[l.size()]);
    // _array= make_shared<T[]>(l.size());
    _capacity=l.size();
    _size=0;
    for(T f :l ){
        add_figure(f);
    }
    // _size=l.size();

} 

template <class T> 
bool F_array<T>::add_figure(T f){
    if(_size==_capacity){
        int new_cap=_capacity*K;
        // auto new_array = make_shared<T[]>(new_cap);
        auto new_array=shared_ptr<T[]>(new T[new_cap]);
        for(int i=0; i<_size;++i){
            new_array[i]=_array[i];
        }
        _capacity=new_cap;
        _array=new_array;

    }
    _array[_size]=f;
    _size++;
    return true;
}

template<class T>
T F_array<T>::get_figure(const int indx){
    if(_size>=indx and indx>0){
        return _array[indx];
    }
}

template<class T>
F_array<T>::F_array( F_array<T> &f_a){
    _size=f_a._size;
    _capacity=f_a._capacity;
    auto _array=shared_ptr<T[]>(new T[_size]);
    // auto _array = make_shared<T[]>(_size);
    // _array= new Figure*[_size];
    for(int i=0; i<_size;++i){
        this->add_figure(f_a.get_figure(i));
    }
}


template<class T>
F_array<T>::F_array(F_array<T> &&f_a)noexcept{
    _size=f_a._size;
    _capacity=f_a._capacity;
    _array=f_a._array;
    f_a._size=0;
    f_a._capacity=0;
    f_a._array=NULL;
}

template<class T>
bool F_array<T>::del_figure(const int indx){
    vector<Coord<double>>().swap((*_array[indx])._array);
    if(_size>=indx and indx>0){
        for(int i=indx;i<_size-1;++i){
            _array[i]=_array[i+1];
        }

        _size--;
        return true;
    }
    return false;
}

template<class T>
double F_array<T>::common_s() {
    double tmp=0;
    for(int i=0; i<_size;++i){
        tmp+=(double) *(_array[i]);
    }
    return tmp;
}

template<class T>
void F_array<T>::print_s(){
    for(int i=0;i<_size;++i){
        cout<<"Figure"<<i<<": n="<<(*_array[i])._angles_count<<" S="<< double(*_array[i])<<'\n';
    }
}

template<class T>
void F_array<T>::print_geom_centre(){
    for(int i=0; i<_size;++i){
        // template<Number N>
        Coord<double> tmp;
        tmp=(*_array[i]).get_coord();
        cout<<"Geom.centre Figure"<<i<<": x="<<tmp.x<<" y="<<tmp.y<<'\n';
    }
}

template<class T>
F_array<T>::~F_array(){
    if(_size>0){
        _capacity=0;
        _size=0;
        _array=NULL;
    }
}

template<class T>
int F_array<T>::get_size(){
    return this->_size;
}