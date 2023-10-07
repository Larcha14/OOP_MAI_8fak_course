#pragma once
#include <iostream>
#include "vector.h"
#include <string>
using namespace std;

#define Radix_baze 16

//H07A в массиве будет представляться как A70H!!!

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
        // friend Hex operator--(Hex &h, int);
        // friend Hex& operator--(Hex &h);

        bool operator == (const Hex &h) const;
        bool operator > (const Hex &h);
        bool operator < (const Hex &h);
        Hex operator+(const Hex &other);
        Hex operator-(const Hex &other);
        ostream &print(ostream &os); // при завершении очищает буфер
        int len();

        virtual ~Hex() noexcept;
    private:
        size_t _size;
        unsigned char *_array;

};

// inline int max_len(Hex &h1, Hex &h2){

// }

