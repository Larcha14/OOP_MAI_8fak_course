#include <iostream>
#include "gcd.h"
using namespace std;

int main(){
    int a,b;
    double a1, b1;
    cout<<"Input 2 integers ";
    cin>>a1>>b1;
    a=int(a1);
    b=int(b1);
    cout<<"GCD ("<<a<<' '<<"and "<<b<<") = ";
    int ans=gcd_2(abs(b),abs(a));
    if(ans==-1){
        cout<<"+INF";
    } else{
        cout<<ans;
    }
    cout<<"\n\n";

}