#include <iostream>
#include "hex.h"


// 2 вариант 
int max_len(Hex &h1, Hex &h2){
    return max(h1.len(), h2.len());
}

int char_to_int(char c){
    int answ;
    if(c>='0' and c<='9'){
        answ=c-'0';
    } else if(c>='A' and c<='F'){
        answ=10+c-'A';
    }else if(c>='a' and c<='f'){
        answ=10+c-'a';
    } else{
        answ=-1;
    }
    return answ;

}

char int_to_char(int a){
    char answ;
    if(a>=0 and a<=9){
        answ=char(a);
    } else if(a>=10 and a<=15){
        answ='A'+a-10;
    } else{
        return '\0';
    }
}

int Hex::len(){
    return _size-1;
}

Hex::Hex() {
    _size=0;
    _array= NULL;
}

Hex::Hex(const size_t &n, unsigned char t){
    _array= new unsigned char[n+1];
    _size=n+1;
    for(int i=0; i<n;++i){
        _array[n-1-i]=t;
    }
    _array[n]='0';

}

Hex::Hex(const initializer_list<unsigned char> &t){
    _array =new unsigned char[t.size()+1];
    int i=t.size()-1;
    for(auto &c :t){
        _array[i--]=c;
    }
    _array[t.size()]='0';
    _size=t.size();
}

Hex::Hex(const string &t){
    _array=new unsigned char[t.size()+1];
    for(int i=0; i<t.size(); ++i){
        _array[i]=t[t.size()-1-i];
    }
    _array[t.size()]='0';
    _size=t.size();
}

Hex::Hex(const Hex &other){
    _size=other._size;
    _array=new unsigned char[_size];
    for(int i=0; i<_size;++i){
        _array[i]=other._array[other._size-1-i];
    }

}

Hex::Hex(Hex &&other) noexcept{
    _size=other._size;
    _array=other._array;
    other._size=0;
    other._array=NULL;
}

bool Hex::operator ==(const Hex &h) const{
    if(this->_size==h._size){
        int l=h._size;
        for(int i=0; i<l;++i){
            if(h._array[i]!=this->_array[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Hex::operator>(const Hex &h){

}

Hex Hex::operator+(const Hex &other){
    int l=max(this->_size, other._size);
    unsigned char tmp[l];
    unsigned char ost=0;
    try{
        for(int i=0; i<min(this->_size, other._size)-1;++i){
            int a1=char_to_int(this->_array[i]);
            int a2= char_to_int(other._array[i]);
            if(a1==-1 or a2==-1){
                throw 1;
            } else{
                char res=int_to_char((a1+a2+ost)%Radix_baze);
                if(res=='\0'){
                    throw 2;
                }
                tmp[i]=res;


                ost=(a1+a2+ost)/Radix_baze;

            }
        tmp[l-1]=int_to_char( ost);

        }
    } catch(int err){
        cout<<"Error";
    }
    this->_array=tmp;
    // Hex new_hex( &&this);


}

ostream &Hex::print(ostream &os){
    for(int i=0; i<_size;++i){
        os<<_array[i];
    }
    return os;
}


Hex::~Hex() noexcept{
    if(_size>0){
        _size=0;
        delete[] _array;
        _array=NULL;
    }
}

// int main(){
//     Hex numb("F07A");
//     Hex numb_2("F07A");
//     // (numb==numb_2).print(cout);
//     bool a= numb==numb_2;
//     cout<<a;
// }