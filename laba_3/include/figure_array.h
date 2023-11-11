#pragma once
#include "figure.h"

#define K 2

class F_array {
    public:
    F_array();
    F_array(const initializer_list<Figure*> &l);
    F_array( F_array &f_a);
    F_array(F_array &&f_a)noexcept;

    double common_s();
    bool add_figure(Figure* f);
    Figure* get_figure(const int indx);
    bool del_figure(const int indx);
    void print_s();
    void print_geom_centre();
    int get_size();

    ~F_array();
    private:
        int _size;
        int _capacity;
        Figure** _array;
};   