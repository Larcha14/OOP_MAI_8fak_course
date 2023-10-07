#include <iostream>
#define k 2
#define MIN_CAP 30
using namespace std;

typedef struct{
    char *buff; //динамический буфер
    int cap; //capacity сколько ячеек мы выделяем для зранения
    int size;
    int head;
    int tail;

} vector_c;

void init(vector_c *v);
void destroy(vector_c *v);
bool push_back(vector_c *v, char val);
bool push_front(vector_c *v,char val);
int pop_back(vector_c *v);
int pop_front(vector_c *v);
bool is_empty(vector_c *v);
int get_size(vector_c *v);
bool set_size(vector_c *v, int new_size);
int get_el(vector_c *v, int idx); //обращение по индексу
void set_el(vector_c *v, int idx, char val);