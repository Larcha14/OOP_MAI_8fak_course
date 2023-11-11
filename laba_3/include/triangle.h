#pragma once
#include "figure.h"

class Triangle: public Figure{
    public:
        Triangle();
        Triangle(const vector<coord> &v);
        Triangle(const initializer_list<coord> &l);
        Triangle(const Triangle &other);
        Triangle(Triangle &&other)noexcept;

        // virtual bool is_correct() override;

};

