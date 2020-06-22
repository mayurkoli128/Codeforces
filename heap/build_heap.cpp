/*

Q : Given an array of N elements. The task is to build a Binary Heap from the given array. 
    The heap can be either Max Heap or Min Heap.

    Simple Approach: Suppose, we need to build a Max-Heap from the above-given array elements. 
    It can be clearly seen that the above complete binary tree formed does not follow the Heap
    property. So, the idea is to heapify the complete binary tree formed from the array in reverse 
    level order following top-down approach.

    That is first heapify, the last node in level order traversal of the tree, then heapify the second
    last node and so on.

    Time Complexity: Heapify a single node takes O(Log N) time complexity where N is the total number 
    of Nodes. Therefore, building the entire Heap will take N heapify operations and the total time 
    complexity will be O(N*logN).

    In reality, building a heap takes O(n) time depending on the implementation which can be seen
    "http://www.cs.umd.edu/~meesh/351/mount/lectures/lect14-heapsort-analysis-part.pdf".


== > OPTIMIZED APROACH....

*/
#include <iostream>
#include <algorithm>

// Operation's
template<class Compare>
void perculateDown(int *arr, int parent_index, int size, Compare cmp)
{
    int lChild = parent_index * 2 + 1;
    int rChild = parent_index * 2 + 2;

    if (lChild >= size) {
        return;
    }
    int swap_with_node_index;
    
    if(rChild >= size) {
        swap_with_node_index = lChild;   
    }
    else if(cmp(arr[lChild], arr[rChild])) {
        swap_with_node_index = lChild;   
    }else {
        swap_with_node_index = rChild;   
    }
    // swap operation...
    if(cmp(arr[swap_with_node_index], arr[parent_index])) {
        std :: swap(arr[swap_with_node_index], arr[parent_index]);
        perculateDown(arr, swap_with_node_index, size, cmp);
    }
}
template<class Compare>
void heapify(int *arr, int start, int size, Compare lamda)
{
    for (int i = (size - 1) / 2; i >= 0; i--){
        perculateDown(arr, i, size, lamda);
    }
}
void print_array(int* arr, int size) {
    for(int i = 0; i < size; ++i) {
        std :: cout << arr[i] << " ";
    }
    std :: cout << "\n";
}
template<class Compare>
void heap_sort(int* arr, int size, Compare lamda) {
    heapify(arr, 0, size, lamda);

    for(int i = size - 1; i >= 0; --i) {
        //std :: cout << "Perculate down for " << arr[i] << "\n";
        std :: swap(arr[0], arr[i]);
        //print_array(arr, size);
        perculateDown(arr, 0, i, lamda);
    }
    std :: cout << "\nArray is sorted : ";
    print_array(arr, size);
}

int main()
{
    int arr[] = {7148,7454,6800,3291,6460,-9062,1113,-6854,5408,-9912,-9050,3896,338,-8136,-6832,-131,2446,2225,5421,6020,9099,-6575,6392,-603,-4813,1979,-8388,-3993,492,9099,1300,-8854,8676,1379,-3282,-8602,9114,8541};
    //int arr[] = {6, 5, 9, -8, 7, 2, 1, 3};
    int size = sizeof(arr) / sizeof(int);

    auto lamda = [] (const int& a, const int& b) {
        return a > b;
    };

    heap_sort(arr, size, lamda);

    if (std ::is_heap(arr, arr + size, std :: greater<int>()))
        std ::cout << "\nConversion Successsful..";
    return 0;
}
