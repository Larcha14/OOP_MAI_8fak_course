// #include "./include/allocate.h"
#include "./include/vector.h"
#include <map>
using namespace std;

int main(){
    map<int, int, less<int>, My_allocator::Allocator<pair<const int, int>, 128>> my_map;
    my_map[0]=0;
    my_map[1]=1;

    for(int i=2; i<=9;++i){
        my_map[i]=my_map[i-1]*i;
    }

    for(const auto& [k,v]: my_map)
        std::cout << k << "->" << v << std::endl;

    // My container:

    Myvector<int, My_allocator::Allocator<int, 100>> v(6);
    // Myvector<int, 100> v(10);

    // cout<<'\n'<<v.size();
    // cout<<'\n';
    // cout<<v.capacity();
    // cout<<'\n';
    // for(int i=0; i< v.size();++i){
    //     v[i]=i;
    // }
    // for(int i=0; i<v.size();++i){
    //     cout<<v[i]<<' ';
    // }
    // int a=10;
    // v.push_back(a);

    //     cout<<'\n';
    // cout<<v.capacity();
    //     cout<<'\n'<<v.size();


    // cout<<v.front();
    // cout<<v.size()<<' '<<v.capacity();
    // cout<<'\n';
    // for(int i=1; i<10;++i){
    //     v.push_back(i);
    // }
    // cout<<v.size()<<' '<<v.capacity();
    // cout<<'\n'<<v.front()<<" - "<<v.back();

    for(int i=0; i<6;++i){
        v[i]=i;
    }
    auto it1=v.begin();
    v.insert(it1.next(it1, 1), 10);
    cout<<v.size()<<'\n';
    for(int i=0; i<v.size();++i){
        cout<<i<<"= "<<v[i]<<'\n';
    }
    


    
}