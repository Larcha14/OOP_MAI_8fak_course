#pragma once
#include "figure.h"

template <Number T> 
class Hexagon: public Figure<T>{
    public:
        Hexagon();
        Hexagon(const vector<Coord<T>> &v);
        Hexagon(const initializer_list<Coord<T>> &l);
        Hexagon(const Hexagon<T> &other);
        Hexagon(Hexagon<T> &&other)noexcept;

};

template <Number T> 
Hexagon<T>::Hexagon(): Figure<T>(6){

}

template <Number T> 
Hexagon<T>::Hexagon(const vector<Coord<T>>&v):Figure<T>(v, 6){

}
template <Number T> 
Hexagon<T>::Hexagon(const initializer_list<Coord<T>> &l):Figure<T>(l,6){
    
}

template <Number T> 
Hexagon<T>::Hexagon(const Hexagon<T> &other):Figure<T>(other){

}

template <Number T> 
Hexagon<T>::Hexagon(Hexagon<T> &&other)noexcept:Figure<T>(other){

}

