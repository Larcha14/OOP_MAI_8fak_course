#include <iostream>
#include "hex.h"
// #include <exception>

// 2 вариант 
int Hex::size() const {
    return _size;
}

string Hex::To_str(){
    string s(_size, '0');
    for(int i=_size-1; i>=0;--i){
        s[i]=_array[_size-1-i];
    }
    return s;
}

int max_len(Hex &h1, Hex &h2){
    return max(h1.size(), h2.size());
}

int char_to_int(unsigned char c){
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

unsigned char int_to_char(int a){
    unsigned char answ;
    if(a>=0 and a<=9){
        answ='0'+a;
    } else if(a>=10 and a<=15){
        answ='A'+a-10;
     } else{
        answ= '\0';
    }
    return answ;
}

bool is_hex_elem(char a){
    if (char_to_int(a)==-1){
        return false;
    }
    return true;
}

int Hex::real_leng() const{
    int l=_size;
    for(int i=this->_size-1; i>0; i--){
        if(this->_array[i]!='0'){
            break;
        }
        l--;
    }
    if(this->_size!=0 and l==0){
        l=1;
    }
    return l;
}

void Hex::create_without_zero(){
    if(this->_size !=(this)->real_leng()){
        int l=this->real_leng();
        unsigned char* new_array= new unsigned char[l];
        for(int i=0;i<l;++i){
            new_array[i]=this->_array[i];
        }
        delete [] _array;
        _array=new_array;
        _size=l;
    }
}


Hex::Hex() {
    _size=1;
    _array= new unsigned char[1];
    _array[0]='0';
}

Hex::Hex(const size_t &n, unsigned char t){
    _array= new unsigned char[n];
    _size=n;
    if(is_hex_elem(t)==0){
        throw input_error("Unacceptable value");
    }
    for(int i=0; i<n;++i){
        _array[n-1-i]=t;
    }
    this->create_without_zero();

}

Hex::Hex(const initializer_list<unsigned char> &t){
    _array =new unsigned char[t.size()];
    int i=t.size();
    for(auto &c :t){
        if(is_hex_elem(c)==0){
            throw input_error("Unacceptable value");
        }
        _array[i-1]=c;
        --i;
    }
    _size=t.size();
    this->create_without_zero();
}

Hex::Hex(const string &t){
    _array=new unsigned char[t.size()];
    for(int i=0; i<t.size(); ++i){
        if(is_hex_elem(t[t.size()-1-i])==0){
            throw input_error("Unacceptable value");
        }
        _array[i]=t[t.size()-1-i];
    }
    _size=t.size();
    this->create_without_zero();
}

Hex::Hex(const Hex &other){
    _size=other._size;
    _array=new unsigned char[_size];
    for(int i=0; i<_size;++i){
        _array[i]=other._array[i];
    }
    this->create_without_zero();
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

bool Hex::operator>(const Hex &h) const{
    if(this->_size>h._size){
        return true;
    }else if(this->_size==h._size){
        int check=0;
        for(int i=h._size-1; i>=0;--i){
            char a1=_array[i];
            char a2=h._array[i];
            if(char_to_int(a1)<char_to_int(a2)){
                return false;
            }
            if(_array[i]==h._array[i]){
                check++;
            }
        }
        if(check==h._size){
            return false;
        }
        return true;
    }
    return false;

}

bool Hex::operator<(const Hex &h) const{
    if(this->_size<h._size){
        return true;
    }else if(this->_size==h._size){
        int check=0;
        for(int i=h._size-1; i>=0;--i){
            char a1=_array[i];
            char a2=h._array[i];
            if(char_to_int(a1)>char_to_int(a2)){
                return false;
            }
            if(_array[i]==h._array[i]){
                check++;
            }
        }
        if(check==h._size){
            return false;
        }
        return true;
    }
    return false;
}

Hex& Hex::operator+(const Hex &other){
    int l=max(this->_size, other._size);
    int min_l= min(this->_size, other._size);
    unsigned char* tmp= new unsigned char[l+1];
    int ost=0;
    for(int i=0; i<min_l;++i){
        int a1=char_to_int(this->_array[i]);
        int a2= char_to_int(other._array[i]);
        unsigned char res=int_to_char((a1+a2+ost)%Radix_baze);
        tmp[i]=res;
        ost=(a1+a2+ost)/Radix_baze;
    }
    if(l>min_l){
        if(this->_size>min_l){
            for(int i=min_l; i<l;++i){
                int a=char_to_int(this->_array[i]);
                unsigned char res=int_to_char((a+ost)%Radix_baze);
                tmp[i]=res;
                ost=(a+ost)/Radix_baze;
            }
        } else{ // other.size<l
            for(int i=min_l; i<l;++i){
                int a=char_to_int(other._array[i]);
                unsigned char res=int_to_char((a+ost)%Radix_baze);
                tmp[i]=res;
                ost=(a+ost)/Radix_baze;
            }
        }
    }
    tmp[l]=int_to_char(ost);
    delete [] _array;
    _size=l+1;
    this->_array=tmp;
    this->create_without_zero();
    return *this;

}

Hex& Hex::operator-(const Hex &other){
    if((*this<other)==true){
        throw input_error("Try to get a negative number");
    } else{
        int l=max(this->_size, other._size); //always be this->size
        int min_l= min(this->_size, other._size);
        unsigned char* tmp= new unsigned char[l];
        int debt=0;
        for(int i=0; i<min_l;++i){
            int a1=char_to_int(this->_array[i]);
            int a2= char_to_int(other._array[i]);
            unsigned char res=int_to_char((a1-a2+Radix_baze-debt)%Radix_baze);
            tmp[i]=res;
            if((a1-a2-debt)>=0){
                debt=0;
            }else{
                debt=1;
            }

        }
        if(l>min_l){
            for(int i=min_l; i<l;++i){
                int a=char_to_int(this->_array[i]);
                unsigned char res=int_to_char((a-debt+Radix_baze)%Radix_baze);
                tmp[i]=res;
                if((a-debt)>=0){
                    debt=0;
                }else{
                    debt=1;
                }
                // debt=(abs(a-debt)+Radix_baze-1)/Radix_baze;
            }
        }
        delete [] _array;
        this->_size=l;
        this->_array=tmp;
        this->create_without_zero();
        return *this;
    }

}

ostream &Hex::print(ostream &os) const{
    for(int i=_size-1; i>=0;--i){
        os<<(_array[i]);
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
//     try{
//         Hex h_2("0");
//         Hex h;
//         (h_2-h_2).print(cout)<<'\n';
//         cout<<(h==h_2);

//     } catch(const input_error& err){
//         cout<<"Error: "<< err.what()<<'\n';
//     }
// }