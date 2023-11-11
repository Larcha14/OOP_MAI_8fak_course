#pragma once
#include "figure.h"

class Octagon: public Figure{
    public:
        Octagon();
        Octagon(const vector<coord> &v);
        Octagon(const initializer_list<coord> &l);
        Octagon(const Octagon &other);
        Octagon(Octagon &&other)noexcept;
  
};