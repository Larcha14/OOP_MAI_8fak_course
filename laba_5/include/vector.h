#pragma once
#include <iostream>
#include <memory>
#include "allocate.h"
using namespace std;

#define MIN_CAP 10
#define K 2

// My_allocator::Allocator<T, BLOCK_SIZE>
// template<class T, size_t BLOCK_SIZE, class ALLOCATOR = My_allocator::Allocator<T, BLOCK_SIZE>>

template<class T, class ALLOCATOR >
class Myvector{
    public:
        class Iterator{
            public:
                using difference_type = ptrdiff_t ; 
                using value_type = T;
                using reference =T& ;
                using pointer = T*;
                using iterator_category = forward_iterator_tag;

                Iterator(Myvector &v, int i): vector(v), idx(i){
                }

                reference operator*(){
                    return vector[idx];
                }
                pointer operator->(){
                    return &vector[idx];
                }

                Iterator& operator++(){
                    idx++;
                    return *this; 
                }

                Iterator next(Iterator &start, int s){
                    int cur_ind= start.idx;
                    for(int i=0;i<cur_ind+s;++i){
                        ++start;
                    }
                    return start;

                }


                // Iterator next(int s){
                //     int cur_ind= this->idx;
                //     for(int i=0;i<cur_ind+s;++i){
                //         this++;
                //     }
                //     return *this;

                // }

                bool operator!=(const Iterator &other) const{
                    if(idx!=other.idx) return true;
                    if(&vector!=&(other.vector)) return true;
                    return false;
                }

                bool operator ==(const Iterator &other) const{
                    if(&vector!=&(other.vector)) return false;
                    if(idx==other.idx) return true;
                    return false;
                }
            private:
                Myvector& vector;
                size_t idx;
                friend class Myvector;
        };
    public:
        using Const_iterator = Iterator;
        // using allocator_type = ALLOCATOR;
        using Allocator_traits = allocator_traits<ALLOCATOR>;

        using difference_type = ptrdiff_t ; 
        using value_type = T;
        using reference = T& ;
        using pointer = T*;

        Myvector(): _size(0), _capacity(0){
            _array=Allocator_traits::allocate(_allocator, 1);
        }
        Myvector(initializer_list<value_type> v){
            _size=v.size();
            _capacity=_size*K;
            _array=Allocator_traits::allocate(_allocator, _capacity);
            int i=0;
            for(const value_type &elem: v){
                _array[i]=elem;
                i++;
            }
        } 
        Myvector(size_t ln){
            _size=ln;
            _capacity=ln*K;
            _array=Allocator_traits::allocate(_allocator, _size);

        }
        Myvector(size_t ln, value_type var){
            _size=ln;
            _capacity=ln;
            _array=Allocator_traits::allocate(_allocator, _capacity);
            for(int i=0; i<_size;++i){
                _array[i]=var;
            }
        }
        Myvector(const Myvector &other){
            this->resize(other._size);
            for(int i=0; i<other._size; ++i){
                this->_array[i]=other._array[i];
            }
        }
        Myvector(Myvector &&other):Myvector(other._size){
            *this=move(other);
            other=nullptr;
        }
        Myvector &operator=(const Myvector &other){
            this->resize(other._size);
            for(int i=0; i<other._size; ++i){
                this->_array[i]=other._array[i];
            }
            return *this;
        }
        Myvector &operator=(Myvector &&other) noexcept{
            this->resize(other._size);
            for(int i=0; i<other._size; ++i){
                this->_array[i]=other._array[i];
                Allocator_traits::destroy(_allocator, other._array+i);
            }
            Allocator_traits::deallocate(_allocator, other._array, other._size);
            
            other._array=nullptr;
            return *this;
        }


        size_t size(){
            return _size;
        }
        size_t capacity(){
            return _capacity;
        }
        Iterator begin(){
            return Iterator(*this, 0);
        }
        Iterator end(){
            return Iterator(*this, size());
        }
        Const_iterator cbegin() const{
            return Const_iterator(*this, 0);
        }
        Const_iterator cend() const {
            return Const_iterator(*this, size());
        }

        reference front(){
            if(_size>0){
                return _array[0];
            } else{
                throw logic_error("_size of vector == 0 ");
            }
        }

        reference back(){
            if(_size>0){
                return _array[_size-1];
            } else{
                throw logic_error("_size of vector == 0 ");
            }
        }

        reference operator[](size_t pos){
            if(pos >=0 and pos <=_size){
                return _array[pos];
            } else{
                throw logic_error("Seq fault");
            }
        }

        void reserve(size_t n){
            if(n<=_capacity){
                return;
            } else{
                pointer new_arr= Allocator_traits::allocate(_allocator, n);
                _capacity=n+_capacity;
                // _size=n;

            }
        }

        void resize(size_t n){
            if(n>_capacity){
                reserve(n);
            } else{

            }
            _size=n;
        }

        void pop_back(){
            if(_size>0){
                _size--;
            } else{
                throw logic_error("Try to pop zero-size vector");
            }
            // if(_size<_capacity/K){
            //     resize(_capacity/K);
            // }
        }
        Iterator insert(Iterator pos, value_type val){
            if (pos.idx>_size){
                throw logic_error("Seg fault");
            } else{
                if(_size>=_capacity){
                    resize(_size+1);
                } else{
                    _size++;
                }
                for(int i=_size; i>pos.idx; i--){
                    _array[i]=_array[i-1];
                }
                _array[pos.idx]=val;

            }
        }

        void push_back(const T& val){
            if(_size>=_capacity){
                reserve(_size+1);
            }
            _array[_size]=val;
            ++_size;
        }

        ~Myvector(){
            Allocator_traits::deallocate(_allocator, _array, _capacity);
            _size=0;
            _capacity=0;
            _array=nullptr;

        }
    private:
        int _size;
        int _capacity;
        T* _array;        
        ALLOCATOR _allocator;
        //  allocator;
};

//erase+insert
