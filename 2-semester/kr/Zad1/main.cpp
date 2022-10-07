#include <iostream>


class triple_heap
{
    int capacity;
    int last_index;
    int* data;
public:
    triple_heap(int* values, int max_size);
    triple_heap(triple_heap& H);
    ~triple_heap(); // удаляем массив
    void sift_up(int index); // фиксит кучу при добавлении элемента вниз начиная снизу
    void sift_down(int index); // фиксит кучу начиная сверху

    void insert(int val); // добавляем в конец, включаем sift_up от last_index- нового

    int extract_max();

    int get_max_size();
    int get_current_size();
    
    int get(int index);
};



triple_heap::triple_heap(triple_heap& H)
{
    capacity = H.get_max_size();
    last_index = H.get_current_size()-1;

    data = new int[capacity];

    for (int i = 0; i <= last_index; i++)
        data[i] = H.get(i);
}


int triple_heap::extract_max()
{
    int max = data[0];
    data[0] = data[last_index];
    // последний можно не удалаять, так как мы следим по last_index
    last_index--;

    sift_down(0);

    return max;
}