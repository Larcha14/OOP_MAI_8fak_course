#pragma once
#include <iostream>
#include "vector.h"
#include <string>
#include <cstring>
#include <exception>
using namespace std;

#define Radix_baze 16

//H07A в массиве будет представляться как A70H!!!
class input_error: public exception{
    public:
        input_error(const string& message): message{message}
        {}
        const char* what() const noexcept override{
            return message.c_str();
        }
    private:
        string message;

};

class Hex{
    public:
        Hex();
        Hex(const size_t &n, unsigned char t=0);
        Hex(const initializer_list<unsigned char> &l);
        Hex(const string &s);
        Hex(const Hex &other); //копирующий конструктор
        Hex(Hex &&other) noexcept; //==move??

        // friend Hex operator++(Hex &h, int);
        // friend Hex& operator++(Hex &h);
        // friend Hex operator--(Hex &h, int);s
        // friend Hex& operator--(Hex &h);

        bool operator == (const Hex &h) const;
        bool operator > (const Hex &h) const;
        bool operator < (const Hex &h) const;
        Hex &operator+(const Hex &other);
        Hex &operator-(const Hex &other);
        void create_without_zero();
        string To_str();
        ostream &print(ostream &os) const; 
        int size() const ;
        int real_leng() const ;


        ~Hex() noexcept;
    private:
        size_t _size;
        unsigned char *_array;

};

