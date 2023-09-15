#include "gcd.h"

int gcd(int a, int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}

int gcd_1(int a, int b){
    if(a==0 and b==0){
        return -1;
    } else if( a==0){
        return b;
    }else if(b==0){
        return a;
    } else{
        return gcd(abs(b),abs(a));
    }
}
