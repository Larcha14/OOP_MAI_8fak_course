#include "./include/hexagon.h"

Hexagon::Hexagon(): Figure(6){

}

Hexagon::Hexagon(const vector<coord>&v):Figure(v, 6){

}
Hexagon::Hexagon(const initializer_list<coord> &l):Figure(l,6){
    
}

Hexagon::Hexagon(const Hexagon &other):Figure(other){

}

Hexagon::Hexagon(Hexagon &&other)noexcept:Figure(other){

}

// int main(){
//     vector<coord> c(6);
//     c[0].x=2;
//     c[0].y=0;
//         c[1].x=1.39;
//     c[1].y=1.28;
//         c[2].x=-0.02;
//     c[2].y=1.4;
//         c[3].x=-0.83;
//     c[3].y=0.23;

//         c[4].x=-0.22;
//     c[4].y=-1.05;
//         c[5].x=1.19;
//     c[5].y=-1.16;
//     // for(int i=0; i<4;++i){
//     //     c[i].x=i%2;
//     //     c[i].y=1-i%2;
//     // }
//     Hexagon f1(c);
//     coord a=f1.get_coord();
//     // cout<<a.x<<' '<<a.y;
//     // cout<<double(f1);
//     f1.print_array();
//     // double r1=0.101112;
//     // double r2=0.1012341;
//     // cout<<'\n'<<double_cmp(r1,r2);
    
// }