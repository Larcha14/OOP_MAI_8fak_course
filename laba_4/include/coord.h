#pragma once
#include <iostream>
#include <concepts>
#include <math.h>
using namespace std;

#define MY_EPS 2*1e-2


template <class T>
concept Number = convertible_to<T, double> || floating_point<T>;

template <Number T> 
class Coord{
    public:
        Coord();
        Coord(T x, T y);
        T x;
        T y;
        ~Coord(); 
};

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

template <Number T> 
bool double_cmp(T a, T b){
    // int a1, b1;
    // a1=a*MY_EPS;
    // b1=b*MY_EPS;
    // if(int(abs(b-a)*MY_EPS)==0){
    //     return true;
    // }
    T r=a-b;
    // cout<<"My eps="<<MY_EPS<<"  rasn ="<<r<<'\n';
    if((r>0 and r<MY_EPS) or(r<0 and (r*(-1)<MY_EPS)) or r==0){
        return true;
    }
    return false;
}

template <Number T> 
T distance(Coord<T> a, Coord<T> b){
    double d=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return d;
}



// template <Number T> 
// bool cmp(Coord<T> a, Coord<T> b){
//     if(a.x==b.x){
//         return a.y>b.y;
//     }
//     return a.x>b.x;
// }




// template <Number T> 
// T distance(Coord<T> a, Coord<T> b); 

// template <Number T> 
// bool double_cmp(T a, T b); 

// template <Number T> 
// bool cmp(Coord<T> a, Coord<T> b);