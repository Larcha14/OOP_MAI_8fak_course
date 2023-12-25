#pragma once
#include <iostream>
#include <memory>
#include <array>
#include <map>
using namespace std;

#define N 8192
#define CHUNK_SIZE 32


namespace My_allocator{
    template<class T, size_t BLOCK_SIZE>
    class Allocator{
        // typedef struct item{
        //     bool used;
        //     T* ptr;
        // };
        private:
            size_t _free_idx;
            size_t _count_of_blocks=BLOCK_SIZE/CHUNK_SIZE;
            map<T*, bool> _used_blocks;
            // array<item, BLOCK_SIZE> _used_blocks;
            // item _used_blocks[BLOCK_SIZE];
            array<T, BLOCK_SIZE> _free_blocks;
            
            // array<T*, BLOCK_SIZE/CHUNK_SIZE> _free_blocks;
            // T* _free_blocks;
        public:
            static constexpr size_t max_count = BLOCK_SIZE;
            using value_type = T;
            using pointer = T *;
            using const_pointer = const T *;
            using size_type = size_t;

            Allocator(){
                // _free_blocks= new value_type[max_count];
                // for(int i=0;i<BLOCK_SIZE; ++i){
                //     item tmp;
                //     tmp.used=false;
                //     tmp.ptr=&_free_blocks[i];
                //     _used_blocks[i]=tmp;
                // }
                _free_idx=0;
                
            }
            
    #ifdef DEBUG
                std::cout << "allocator: memory init" << std::endl;
    #endif
            ~Allocator(){
    #ifdef DEBUG
                std::cout << "allocator: deallocate" << std::endl;
    #endif
            }

            template <typename U>//при вызове сложной структуры
            struct rebind
            {
                using other = Allocator<U, BLOCK_SIZE>;
            };

            pointer allocate(size_t n){
                pointer result = nullptr;
                // if (_free_idx+n<max_count){
                //     result=(T*)_free_blocks[_free_idx];
                //     _free_idx=_free_idx+n;
                //     result = (T *)_free_blocks[--_free_idx];
// #ifdef DEBUG
//                     std::cout << "allocator: Allocate " << (max_count - _free_idx) << " of " << max_count << " Address:" << result << std::endl;
// #endif
                // }
                
                if (_free_idx +n < BLOCK_SIZE)
                {
                    result = (T*)&_free_blocks[_free_idx];
                    _free_idx+=n;
                    _used_blocks[result]=true;
                    
                    
#ifdef DEBUG
                    std::cout << "allocator: Allocate " << (_count_of_blocks-_free_idx) << " of " << _count_of_blocks << " Address:" << result << std::endl;
#endif
                }
                else
                {
                    throw logic_error("allocator: No memory exception");
                }
                return result;
            }
            void deallocate(pointer point, size_t n){
                if(_free_idx-n<0 or _used_blocks[point]==false){
                    throw logic_error("allocator: Try to free zero-capacity");
                } else{

            

    #ifdef DEBUG
                cout << "allocator: Deallocate block "<<point << endl;
    #endif
                    // for(int i=_free_idx-1; i>=_free_idx-n;--i){
                    //     _used_blocks[i]=false;
                    // }
                    _used_blocks[point]=false;
                    _free_idx-=n;
                }
            
            }

            template <typename U, typename... Args>
            void construct(U *p, Args &&...args){ //используется аллокатором для создания объекта
                new (p) U(forward<Args>(args)...);
            }

            void destroy(pointer p){
                p->~T();
            }

    };

    template <class T, class U>
    constexpr bool operator==(const  Allocator<T,N > &lhs, const Allocator<U, N> &rhs) 
    {
        return true;
    }

    template <typename T, typename U, size_t BLOCK_COUNT>
    constexpr bool operator!=(const Allocator<T, N> &lhs, const Allocator<U, N> &rhs)  
    {
        return false;
    }
}