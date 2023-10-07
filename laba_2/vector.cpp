#include "vector.h"


static bool increase(vector_c *v){
    int new_cap= v->cap*k;
    if (new_cap<MIN_CAP){
        new_cap=MIN_CAP;
    }
    char *tmp=(char*)realloc(v->buff, new_cap*sizeof(char));
    if(tmp==NULL){
        return false;
    }
    v->buff=tmp;
    if(v->tail<=v->head && v->size!=0){
        for(int i=0; i<v->tail; ++i){
            v->buff[v->cap+i]=v->buff[i];
        }
    }
    v->cap=new_cap;
    return true;
}

static void decrease_if_possible(vector_c *v){
    if(v->size<=v->cap/(k*k)){
            
            int new_cap=v->cap/k;
            if (new_cap<MIN_CAP){
                return;
            }
            if (new_cap<v->cap && v->size>0){
                int new_r =new_cap-1;
                if(v->head>=new_r && (v->tail>new_r || v->tail==0) ){ // [  | ## ] + [  |## ] + [  | ##] -> [## | ]
                    for(int i=0; i<v->size;++i){
                        v->buff[i]=v->buff[v->head+i];
                    }
                    v->head=0;
                    v->tail=v->size;
                }
                if(v->head<new_r && v->tail>new_r){ // [  #|#  ] -> [#  #| ]
                    for(int i=0; i<v->tail-new_r-1;++i){
                        v->buff[i]=v->buff[new_r+1+i];
                    }
                    v->tail=v->tail-new_r-1;
                }
                if (v->tail<new_r && v->head>new_r){ // [#  |  #] -> [#  #| ]
                    for(int i=0; i<v->head-v->cap;++i){
                        v->buff[new_r]=v->buff[v->cap-1-i];
                        new_r--;
                    }
                    new_r++;
                    v->head=new_r;
                }
            }
            v->buff=(char *)realloc(v->buff, new_cap*sizeof(char));
            v->cap=new_cap;
    }

}


void init(vector_c *v){
    v->buff = (char*)malloc(MIN_CAP* sizeof(char));
    v->size=0;
    v->head=0;
    v->tail=0;
    increase(v);
}

void destroy(vector_c *v){
    v->size=0;
    free(v->buff);
    v->cap=0;
    v=NULL;

}

bool set_size(vector_c *v, int new_size) {
    if (new_size == v->size) {
        return true;
    } else if (new_size > v->cap) {
        int new_cap = v->cap * 2;
        while (new_cap < new_size) {
            new_cap *= 2;
        }
        char *tmp = (char *) realloc(v->buff, sizeof(char) * new_cap);
        if (tmp == NULL) {
            return false;
        }
        for (int i = v->cap; i < new_cap; i++) {
            tmp[i] = 0;
        }
        v->buff = tmp;
        if (v->head + v->size > v->cap) {
            for (int i = 0; i < (v->head + v->size) - v->cap; i++) {
                v->buff[v->cap + i] = v->buff[i];
                v->buff[i] = 0;
            }
        }
        v->size = new_size;
        v->tail = v->head + v->size;
        v->cap = new_cap;
        return true;
    } else if (new_size < v->size) {
        for (int i = new_size; i < v->size; i++) {
            v->buff[(v->head + i) % v->cap] = 0;
            v->tail = (v->tail - 1 + v->cap) % v->cap;
        }
        v->size = new_size;
        return true;
    } else {
        v->size = new_size;
        v->tail = v->head + v->size;
        return true;
    }
}

static void zero_range(vector_c *v, int f, int t){ //вспомогательная функция для set_size
    for(int j=f; j<t; ++j ){
        v->buff[j]=0;
    }

}

void set_el(vector_c *v, int idx, char val){
    v->buff[(idx+v->head)%v->cap]=val;
}

int get_el(vector_c *v, int idx){
    return v->buff[(idx+v->head)%v->cap];
}

int pop_back(vector_c *v){
    int val=v->buff[(v->cap+ v->tail-1)%v->cap];
    decrease_if_possible(v);
    v->size--;
    v->tail=(v->cap+ v->tail-1)%v->cap;
    return val;
}

int pop_front(vector_c *v){
    int val= v->buff[v->head];
    decrease_if_possible(v);
    v->size--;
    v->head=(v->head+1)%v->cap;
    return val;
}

bool is_empty(vector_c *v){
    return v->size==0;
}

int get_size(vector_c *v){
    return v->size;
}

bool push_back(vector_c *v, char val){
    if (v->size>=v->cap){
        if (!increase(v)){
            return false;
        }
    }
    v->buff[(v->size+v->head)%v->cap]=val;
    v->size++;
    v->tail=(v->tail+1)%(v->cap+1);
    return true;
}

bool push_front(vector_c *v, char val){
    if (v->size>=v->cap){
        if (!increase(v)){
            return false;
        }
    }
    v->head=(v->cap+v->head-1)%v->cap;
    v->buff[v->head]=val;
    v->size++;
    return true;
}


// int main(){
//     vector_c v;
//     init(&v);
//     set_size(&v, 52);
//     for(int i=0; i< 10; ++i){
//         set_el(&v, i, i);
//         printf("%d ", (&v)->buff[i]);
//     }
//     cout<<"hui\n"<<v.head;
//     // set_size(&v, 41);
//     // set_size(&v,80);
//     // for(int i=40; i<80;++i){
//     //     set_el(&v, i, i);
//     // // }
//     for (int i=0; i<52;++i){
//         printf("%d ", get_el(&v, i));
//     }
    
// }