
// The first line contains two numbers n and m (1≤n,m≤100000), the size of the array and the number of operations. The next line contains n numbers ai, the initial state of the array (−109≤ai≤109). 

// The following lines contain the description of the operations. 

// The description of each operation is as follows: i v, assign the value v to the element with index i (0≤i<n, −109≤v≤109).

#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
typedef long long ln;
using namespace std;

class seg_tree {
private :
    ln size;
    vector<pair<ln, ln>> segment;

    pair<ln, ln> find_pair(pair<ln, ln>& p1, pair<ln, ln>& p2) {
        ln max_sum = max(p1.first, max(p2.first, p1.second + p2.second));

        return make_pair(max_sum, p1.second + p2.second);
    }

    void build(vector<ln>& vec, ln lx, ln rx, ln index, ln size) {
        if(lx - rx == 0) {
            if(lx < size)
                segment[index] = {vec[lx], vec[lx]};
            return;
        }

        ln mid = lx - (lx - rx) / 2;

        build(vec, lx, mid, index*2 + 1, size);
        build(vec, mid + 1, rx, index*2 + 2, size);
        
        segment[index] = find_pair(segment[index*2 + 1], segment[index*2 + 2]);

        return;
    }
    
    void set(ln i, ln val, ln lx, ln rx, ln index) {
        if(lx - rx == 0) {
            if(lx < size)   
                segment[index] = {val, val};
            return;
        }

        ln mid = lx - (lx - rx) / 2;
        
        if(mid >= i) {
            set(i, val, lx, mid, index*2 + 1);
        } else
            set(i, val, mid + 1, rx, index*2 + 2);

        segment[index] = find_pair(segment[index*2 + 1], segment[index*2 + 2]);
    }

    // void traverse(ln index) {
    //     if(index >= 2*size - 1) return ;

    //     cout << "( " << segment[index].first << " ," << segment[index].second << " )\n";
    //     traverse(index*2 + 1);
    //     traverse(index*2 + 2);
    // }

public :

    seg_tree(ln N) {
        size = 1;
        while(size < N)     size *= 2;

        segment.assign(size*2 - 1, {INT64_MIN, 0});
    }
    void build(vector<ln>& vec) {
        build(vec, 0, size - 1, 0, vec.size());
    }
    void set(ln i, ln val) {
        set(i, val, 0, size - 1, 0);        
    }

    ln max_subarray_sum() {
        return segment[0].first;
    }
    
    // void traverse() {
    //     traverse(0);
    // }
    void print() {
        for(ln i = 0; i < size*2 - 1; ++i) {
            cout << "( " << segment[i].first << " ," << segment[i].second << " ) ";
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    ln N, M;
    cin >> N >> M;
    vector<ln> vec(N); 

    seg_tree tree(N);


    for(ln i = 0; i < N; ++i) {
        ln in;
        cin >> in;
        vec[i] = in;
    }

    tree.build(vec);
    tree.print();
    
    ln ans = tree.max_subarray_sum();

     cout << ((ans < 0) ? 0 : ans) << "\n";

    while(M--) {
        ln i, v;
        cin >> i >> v;

        tree.set(i, v);
        ans = tree.max_subarray_sum();
        cout << ((ans < 0) ? 0 : ans) << "\n";
    }
    //tree.traverse();
    return 0;
}