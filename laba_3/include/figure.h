#pragma once
#include <iostream>
#include "coord.h"
#include <vector>
#include <exception>
#include <algorithm>
#include <math.h>
using namespace std;

class Figure{
    friend istream& operator >>(istream& is, Figure &f);
    friend ostream& operator <<(ostream& os, Figure &f);

    public:
        Figure();
        Figure(const int count);
        Figure(const vector<coord> &v, const int count);
        Figure(const initializer_list<coord> &l, const int count);
        Figure(const Figure &jther);
        Figure(Figure &&other)noexcept;

        virtual coord get_coord() const;
        virtual operator double() const;
        virtual int get_angles_count() const;
        virtual bool is_correct();  
        virtual void print_array()const;

        virtual bool operator ==(const Figure &f) const;
        virtual Figure& operator = (const Figure &f);
        virtual Figure& operator = (Figure &&f);



        ~Figure() noexcept; 
               
        int _angles_count;
        int _array_size;
        vector<coord> _array;

    // private:
    //     int _angles_count;
    //     int _array_size;
    //     vector<coord> _array;
};