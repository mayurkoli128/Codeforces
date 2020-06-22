#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <vector>
using namespace std;

struct cmp {
    int xl;
    bool operator() (const int& a, const int& b) {
        return a > b;
    }
};

template<class Compare = cmp>
class priority_queue
{
private:
    int size;
    int *heap;
    int capacity;
    Compare cmp;

    void perculateUp(int unbalanced_node)
    {
        int parent_index = (unbalanced_node - 1) / 2;

        if(cmp(heap[parent_index], heap[unbalanced_node])) {
            std :: swap(heap[parent_index], heap[unbalanced_node]);
            perculateUp(parent_index);
        }     
    }
    void perculateDown(int parent_index)
    {
        int lChild = parent_index * 2 + 1;
        int rChild = parent_index * 2 + 2;

        if (lChild >= size) {
            return;
        }
        int swap_with;
        
        if(rChild >= size) {
            swap_with = lChild;   
        }
        else if(cmp(heap[rChild], heap[lChild])) {
            swap_with = lChild;   
        }else {
            swap_with = rChild;   
        }
        // swap operation...
        if(cmp(heap[parent_index], heap[swap_with])) {
            std :: swap(heap[swap_with], heap[parent_index]);
            perculateDown(swap_with);
        }
    }

public:
    priority_queue() : size(0), capacity(0)
    {
        heap = nullptr;
    }
    priority_queue(int size) : size(0), capacity(size)
    {
        heap = new int[size];
        memset(heap, 0, sizeof(int) * capacity);
    }
    void print()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << heap[i] << " ";
        }
        cout << "\n";
    }
    int top()
    {
        if(empty()) return INT32_MIN;
        return heap[0];
    }
    void push(int val)
    {
        if(size < capacity) {
            heap[size++] = val;

            int unbalanced_node = size - 1;
            perculateUp(unbalanced_node);
        }
    }
    void pop()
    {
        if(size < 0) return;

        swap(heap[size - 1], heap[0]);
        size -= 1;
        perculateDown(0);
    }
    bool empty()
    {
        return size == 0;
    }
    bool is_heap() {
        return std :: is_heap(heap, heap + size, cmp);
    }
};
int main()
{
    int vec[] = {4, 9, 13, 6, 7, 16, 17, 20, -4};
    int size = sizeof(vec) / sizeof(int);

    auto res = kLargest(vec, size, 3);

    for(int i = 0; i < 3; ++i) {
        cout << res[i] << " ";
    }
    return 0;
}