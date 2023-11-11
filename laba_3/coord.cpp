#include "./include/coord.h"

coord::coord(){
    x=0;
    y=0;
}

coord::coord(double x1, double y1){
    this->x=x1;
    this->y=y1;
}

coord::~coord(){
    x=0;
    y=0;
}

bool double_cmp(double a, double b){
    // int a1, b1;
    // a1=a*MY_EPS;
    // b1=b*MY_EPS;
    // if(int(abs(b-a)*MY_EPS)==0){
    //     return true;
    // }
    double r=a-b;
    // cout<<"My eps="<<MY_EPS<<"  rasn ="<<r<<'\n';
    if((r>0 and r<MY_EPS) or(r<0 and (r*(-1)<MY_EPS)) or r==0){
        return true;
    }
    return false;
}

double distance(coord a, coord b){
    double d=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return d;
}

bool cmp(coord a, coord b){
    if(a.x==b.x){
        return a.y>b.y;
    }
    return a.x>b.x;
}

