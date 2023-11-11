#include "./include/octagon.h"

Octagon::Octagon(): Figure(8){

}

Octagon::Octagon(const vector<coord>&v):Figure(v, 8){

}
Octagon::Octagon(const initializer_list<coord> &l):Figure(l,8){
    
}

Octagon::Octagon(const Octagon &other):Figure(other){

}

Octagon::Octagon(Octagon &&other)noexcept:Figure(other){

}