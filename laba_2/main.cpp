#include <iostream>
#include "hex.h"

int main(){
    try{
        Hex a1;
        cout<< "a1 = ";
        a1.print(cout)<<'\n';

        Hex a2("F1A0");
        cout<<"a2 = ";
        a2.print(cout)<<'\n';

        Hex a3={'0', '0', 'A'};
        cout<<"a3 = ";
        a3.print(cout)<<'\n';

        Hex a4(6, '1');
        cout<<"a4 = ";
        a4.print(cout)<<'\n';

        Hex a5(a2);
        cout<<"a5 = ";
        a5.print(cout)<<'\n';

        Hex numb("AA");
        Hex numb_2("B");
        cout<<"AA - B = ";
        (numb-numb_2).print(cout)<<'\n';

        Hex numb_3("FF");
        Hex numb_4("1");
        cout<<"FF + 1 = ";
        (numb_3+numb_4).print(cout)<<'\n';

        cout<<"AA > FF = ";
        cout<<(numb>numb_3)<<'\n';

        cout<<"AA < FF = ";
        cout<<(numb<numb_3)<<'\n';

        cout<<"AA == FF = ";
        cout<<(numb==numb_3)<<'\n';

        cout<<"HH ... ";
        Hex a8("HH");

    } catch(const input_error& err){
        cout<<"Error: "<< err.what()<<'\n';
    }
}