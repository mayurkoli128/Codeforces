#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class seg_tree {
private :
    int size;
    vector<int> segment;

    // API (update)
    void set(int index, int val, int l, int r, int in) {
        if(l - r == 0) {
            segment[in] = val;
            return;
        }

        int mid = l - (l - r) / 2;

        if(mid >= index)
            set(index, val, l, mid, in*2 + 1);
        else
            set(index, val, mid + 1, r, in*2 + 2);

        segment[index] = min(segment[index*2 + 1], segment[index*2 + 2]);
        return;
    }
    // API (get minimum in range)
    int getMin(int l, int r, int lx, int ry, int index) {
        if(l > ry || r < lx)    return INT32_MAX;

        if(lx >= l && ry <= r)  return segment[index];

        int min1, min2;
        
        int mid = lx - (lx - ry) / 2;

        min1 = getMin(l, r, lx, mid, index*2 + 1);
        min2 = getMin(l, r, mid + 1, ry, index*2 + 2);

        return min (min1, min2);
    }
    void traverse(int index) {

        if(index >= size*2 - 1) return ;

        cout << segment[index] << " ";

        traverse(index*2 + 1);
        traverse(index*2 + 2);

        return ;
    }
    void build(vector<int>& vec, int index, int l, int r, int size) {
        if(l - r == 0 && size > l) {
            segment[index] = vec[l];
            return;
        }

        int mid = l - (l - r) / 2;

        build(vec, index*2 + 1, l, mid, size);
        build(vec, index*2 + 2, mid + 1, r, size);

        segment[index] = min(segment[index*2 + 1], segment[index*2 + 2]);
        return;
    }   

public :
    seg_tree(int N) {
        size = 1;
        while(size < N) size *= 2;

        segment.assign(size*2 - 1, INT32_MAX);
    }    
    void build(vector<int>& vec) {
        build(vec, 0, 0, size - 1, vec.size());
    }
    void traverse() {
        traverse(0);
    }
    int getMin(int l, int r) {
        return getMin(l, r, 0, size - 1, 0);
    }
    void set(int index, int val) {
        set(index, val, 0, size - 1, 0);
    }
};

int main() {
int N = 8;
    cin >> N;
    vector<int> vec(N); 

    seg_tree tree(N);


    for(int i = 0 ; i < N; ++i) {
        int in;
        cin >> in;
        vec[i] = in;
    }

    tree.build(vec);

    vector<pair<int, int>> queries = {{0, 1}, {0, 7}, {3, 3}, {4, 4}, {1, 4}, {1, 6}, {5, 7}, {1, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 5}};
    vec[4] = -3;
    vec[5] = -1;

    tree.set(4, vec[4]);
    tree.set(5, vec[5]);
    tree.traverse();
    
    cout << '\n';
    for(int i = 0; i < (int) queries.size(); ++i) {
        auto p = queries[i];

        cout << "( " << p.first << " ," << p.second << " ) : " << tree.getMin(p.first, p.second) << "\n"; 
    }
    // tree.traverse();
    return 0;
}