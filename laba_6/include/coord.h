#pragma once
#include <iostream>
#include <concepts>
#include <math.h>
using namespace std;

template <class T>
concept Number = convertible_to<T, int> ;

template <Number T> 
class Coord{
    public:
        Coord();
        Coord(T x, T y);
        T x;
        T y;
        bool operator ==(const Coord<T> &other);
        T distance(const Coord<T> &other);
        ~Coord(); 
};

template<Number T>
T Coord<T>::distance(const Coord<T> &other){
    int len_deg2;
    len_deg2=(x-other.x)*(x-other.x)+(y-other.y)*(y-other.y);
    int len=sqrt(len_deg2);
    if(len*len!=len_deg2){
        len++;
    } 
    return len;
}

template <Number T> 
bool Coord<T>::operator==(const Coord<T> &other){
    if (this->x==other.x and this->y==other.y){
        return true;
    }
    return false;
}

template <Number T> 
Coord<T>::Coord(){
    x=0;
    y=0;
}

template <Number T> 
Coord<T>::Coord(T x1, T y1){
    this->x=x1;
    this->y=y1;
}

template <Number T> 
Coord<T>::~Coord(){
    x=0;
    y=0;
};
