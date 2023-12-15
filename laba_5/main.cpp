// #include "./include/allocate.h"
#include "./include/vector.h"
#include <map>
using namespace std;

int main(){
    map<int, int, less<int>, My_allocator::Allocator<pair<const int, int>, 128>> my_map;
    my_map[1]=10;
    my_map[2]=20;
    my_map[3]=30;


    for(const auto& [k,v]: my_map)
        std::cout << k << "->" << v << std::endl;
    // Myvector<int, My_allocator::Allocator<int, 1024>> v(10);
    
}