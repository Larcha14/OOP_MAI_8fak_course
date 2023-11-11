#pragma once
#include "figure.h"

class Hexagon: public Figure{
    public:
        Hexagon();
        Hexagon(const vector<coord> &v);
        Hexagon(const initializer_list<coord> &l);
        Hexagon(const Hexagon &other);
        Hexagon(Hexagon &&other)noexcept;

};