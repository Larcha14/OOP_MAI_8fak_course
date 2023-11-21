#pragma once
#include "figure.h"

template <Number T> 
class Octagon: public Figure<T>{
    public:
        Octagon();
        Octagon(const vector<Coord<T>> &v);
        Octagon(const initializer_list<Coord<T>> &l);
        Octagon(const Octagon<T> &other);
        Octagon(Octagon<T> &&other)noexcept;
  
};

template <Number T> 
Octagon<T>::Octagon(): Figure<T>(8){

}

template <Number T> 
Octagon<T>::Octagon(const vector<Coord<T>>&v):Figure<T>(v, 8){

}
template <Number T> 
Octagon<T>::Octagon(const initializer_list<Coord<T>> &l):Figure<T>(l,8){
    
}

template <Number T> 
Octagon<T>::Octagon(const Octagon<T> &other):Figure<T>(other){

}

template <Number T> 
Octagon<T>::Octagon(Octagon<T> &&other)noexcept:Figure<T>(other){

}