#include "./include/figure_array.h"
#include "./include/triangle.h"
#include "./include/octagon.h"
#include "./include/hexagon.h"
using namespace std;


int main(){
    Coord<double> c1(2,0), c2(0.48, 2.39), c3(-0.83, -0.12);
    Triangle<double> t({c1, c2, c3});
    cout<<t;
    cout<<double(t)<<'\n';
    //     cout<<"coord o\n";
    // Coord<double> cento=t.get_coord();
    // cout<<cento.x<<' '<<cento.y<<"\n\n";

    // Triangle& t2(t);
    // cout<<t2._array_size<<'\n';
    Coord<double> ch1(2,0), ch2(1.39,1.28),ch3(-0.02, 1.4),ch4(-0.83, 0.23),ch5(-0.22, -1.05),ch6(1.19,-1.16);
    Hexagon<double> h{ch1,ch2,ch3, ch4,ch5,ch6};
    cout<<double(h)<<'\n';


    Coord<double> co1(3,1), co2(2.41,-0.46),co3(3.02,-1.91),co4(4.48, -2.5),co5(5.92, -1.89),co6(6.52,-0.43),co7(5.91,1.02),co8(4.45, 1.61);
    Octagon<double> o({co1,co2,co3,co4,co5,co6,co7,co8});
    cout<<double(o)<<'\n';

    // cin>>t; // input 2 0 0.48 2.39 -0.83 -0.12
    // cout<<t<<'\n';


    // vector<Coord<double>> c_h(6);
    // c_h[0].x=2;
    // c_h[0].y=0;
    //     c_h[1].x=1.39;
    // c_h[1].y=1.28;
    //     c_h[2].x=-0.02;
    // c_h[2].y=1.4;
    //     c_h[3].x=-0.83;
    // c_h[3].y=0.23;
    //     c_h[4].x=-0.22;
    // c_h[4].y=-1.05;
    //     c_h[5].x=1.19;
    // c_h[5].y=-1.16;
    // Hexagon h(c_h);
    // F_array<shared_ptr<int[]>> mas;
    F_array<shared_ptr<Figure<double>>> mas = {make_shared<Triangle<double>>(t), make_shared<Hexagon<double>>(h)};


    // F_array mas({&t,&h});
    // Coord<double> co1(3,1), co2(2.41,-0.46),co3(3.02,-1.91),co4(4.48, -2.5),co5(5.92, -1.89),co6(6.52,-0.43),co7(5.91,1.02),co8(4.45, 1.61);
    // Octagon o({co1,co2,co3,co4,co5,co6,co7,co8});
    // cout<<o;
    // cout<<double(o);
    // F_array mas({&t,&h});
    cout<<"\n\n size: "<<mas.get_size()<<'\n';
    cout<<"common s="<<mas.common_s()<<"\n\n";
    mas.print_geom_centre();
    cout<<'\n';
    mas.print_s();
    cout<<"\n===========After adding:\n";

    // mas.add_figure(o);
    mas.add_figure(make_shared<Octagon<double>>(o));


    cout<<"common s="<<mas.common_s()<<"\n\n";
    mas.print_geom_centre();
    cout<<'\n';
    mas.print_s();
    cout<<'\n';
    cout<<"==============Get by index\n";
    auto tmp=make_shared<Figure<double>>();
    // Figure<double> *tmp;
    tmp=mas.get_figure(1);
    cout<<*tmp<<'\n';
    cout<<"\n============After deleting last elem\n";
    mas.del_figure(2);
        cout<<"common s="<<mas.common_s()<<"\n\n";
    mas.print_geom_centre();
    cout<<'\n';
    mas.print_s();
    cout<<'\n';
}