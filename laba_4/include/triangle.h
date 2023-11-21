#pragma once
#include "figure.h"

template <Number T> 
class Triangle: public Figure<T>{
    public:
        Triangle();
        Triangle(const vector<Coord<T>> &v);
        Triangle(const initializer_list<Coord<T>> &l);
        Triangle(const Triangle<T> &other);
        Triangle(Triangle<T> &&other)noexcept;

        // virtual bool is_correct() override;

};

template <Number T> 
Triangle<T>::Triangle(): Figure<T>(3){

}

template <Number T> 
Triangle<T>::Triangle(const vector<Coord<T>>&v):Figure<T>(v, 3){

}
template <Number T> 
Triangle<T>::Triangle(const initializer_list<Coord<T>> &l):Figure<T>(l,3){
    
}

template <Number T> 
Triangle<T>::Triangle(const Triangle<T> &other):Figure<T>(other){

}

template <Number T> 
Triangle<T>::Triangle(Triangle<T> &&other)noexcept:Figure<T>(other) {

}