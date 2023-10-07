#include <iostream>
#include "hex.h"

int main(){
    Hex numb("F07A");
    Hex numb_2("F07A");
    // (numb==numb_2).print(cout);
    bool a= numb==numb_2;
    cout<<a;
}