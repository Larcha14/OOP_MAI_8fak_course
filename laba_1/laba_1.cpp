#include <iostream>
#include "gcd.h"
using namespace std;

int main(){
    int a,b;
    cout<<"Input 2 integers ";
    cin>>a>>b;
    cout<<"GCD ("<<a<<' '<<"and "<<b<<") = ";
    int ans=gcd_1(abs(b),abs(a));
    if(ans==-1){
        cout<<"+INF";
    } else{
        cout<<ans;
    }
    cout<<"\n\n";

}