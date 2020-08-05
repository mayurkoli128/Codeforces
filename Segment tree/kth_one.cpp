// In this problem, you need to add to the segment tree the operation of finding the k-th one.

// Input
// The first line contains two numbers n and m (1≤n,m≤100000), the size of the array and the number of operations. The next line contains n numbers ai, the initial state of the array (ai∈{0,1} ). The following lines contain the description of the operations. The description of each operation is as follows:

// 1 i: change the element with index i to the opposite.
// 2 k: find the k-th one (ones are numbered from 0, it is guaranteed that there are enough ones in the array).
// Output
// For each operation of the second type, print the index of the corresponding one (all indices in this problem are from 0).

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> segment(10000005*5);
vector<int> vec(1000005);

int N, M;
int size = 1; 

void update_node(int index) {
    pair<int, int> left = segment[index*2 + 1], right = segment[index*2 + 2];
    segment[index] =  make_pair(left.first + left.second, right.first + right.second);
}

void build(int l, int r, int index) {
    if(l - r == 0) {
        if(l < size)
            segment[index] = make_pair(vec[l], 0);
        return;
    }
    int mid = (l + r) >> 1;

    build(l, mid, index*2 + 1);
    build(mid + 1, r, index*2 + 2);

    update_node(index);
    return;
}
void update(int at, int l, int r, int index) {
    if(l - r == 0) {
        segment[index] = make_pair(!segment[index].first, 0);
        return;
    } 
    int mid = (l + r) >> 1;

    if(mid >= at) {
        update(at, l, mid, index*2 + 1);
    } else {
        update(at, mid + 1, r, index*2 + 2);
    }
    update_node(index);
    return ;
}
int query(int k, int l, int r, int index) {
    
    if(l - r == 0) {
        return l;
    }

    pair<int, int> node = segment[index];

    int mid = (l + r) >> 1;

    if(node.first >= k) {
        return query(k, l, mid, index*2 + 1);
    } 
    return query(k - node.first, mid + 1, r, index*2 + 2);

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    while(size < N) {
        size*= 2;
    }
    // segment.assign(size*2 - 1, {0, 0});

    for(int i = 0; i < N; ++i) {
        int in;
        cin >> in;
        vec[i] = in;
    }

    build(0, size - 1, 0);

    for(int i = 0; i < M; ++i) {
        int q;
        cin >> q;

        if(q == 1) {
            int index;
            cin >> index;
            update(index, 0, size - 1, 0);
        } else {
            int k;
            cin >> k;
            cout << query(k + 1, 0, size - 1, 0) << "\n";
        }
    }   
    return 0;
}   





