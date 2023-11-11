#include "./include/triangle.h"


Triangle::Triangle(): Figure(3){

}

Triangle::Triangle(const vector<coord>&v):Figure(v, 3){

}
Triangle::Triangle(const initializer_list<coord> &l):Figure(l,3){
    
}

Triangle::Triangle(const Triangle &other):Figure(other){

}

Triangle::Triangle(Triangle &&other)noexcept:Figure(other) {

}


// int main(){
//     // vector<coord> c(3);
//     // c[0].x=2;
//     // c[0].y=0;
//     //     c[1].x=0.48;
//     // c[1].y=2.39;
//     //     c[2].x=-0.83;
//     // c[2].y=-0.12;
//     Triangle t;
//     cin>>t;
//     cout<<t;
//     // t.print_array();
//     // cout<<double(t);
    
// }