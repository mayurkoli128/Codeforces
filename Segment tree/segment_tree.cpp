//segment tree for sum...

#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int size;
    vector<long long> segment;

    SegTree(int n) {
        size = 1;

        while(size < n) {
            size *= 2;
        }
        segment.assign(size*2 - 1, 0LL);
    }
    long long get(int l, int r, int index, int lx, int ly) {
        if(l > ly || r < lx)    return 0;

        if(lx >= l && ly <= r)  return segment[index];

        int mid = lx - (lx - ly) / 2;

        int s1, s2;

        s1 = get(l, r, index*2 + 1, lx, mid);
        s2 = get(l, r, index*2 + 2, mid + 1, ly);

        return s1 + s2;
    }

    long long get(int l, int r) {
        long long ans = 0;
        //logic...

        return get(l, r, 0, 0, size - 1);

        return ans;
    }
    void update(int index, int x, int val, int lx, int ry) {
        if(lx - ry == 0) {
            // success..
            segment[x] = val;
            return;
        }

        // finding middle ele..
        int mid = lx - (lx - ry) / 2;

        if(mid < index) {
            update(index, 2*x + 2, val, mid + 1, ry);
        } else {
            update(index, 2*x + 1, val, lx, mid);
        }

        segment[x] = segment[2*x + 1] + segment[2*x + 2];

    }
    void update(int index, int val) {
        update(index, 0, val, 0, size - 1);
    }
    void traverse(int index = 0) {
        if(index >= size*2 - 1)    return;

        cout << segment[index] <<  " ";

        traverse(2*index + 1);
        traverse(2*index + 2);
    }
    void build(vector<int>& vec, int index, int lx, int ly, int size) {

        if(lx - ly == 0 &&  size > lx){
            segment[index] = vec[lx];
            return;
        }

        int mid = lx - (lx - ly) / 2;

        build(vec, index*2 + 1, lx, mid, size);
        build(vec, index*2 + 2, mid + 1, ly, size);

        segment[index] = segment[index*2 + 1] + segment[index*2 + 2];

        return;
    }
    void build(vector<int>& vec) {
        build(vec, 0, 0, size - 1, vec.size());        
    
    }

};
int main() {
    int N = 8;
    cin >> N;
    vector<int> vec(N); //= {3, 1, 2, 5, 6, 4, 3, 2};
    //vector<int> vec = {-1, 3, 4, 0, 2, 1};

    SegTree tree(N);

    // build segment tree in NlogN time complexity...
    // for(int i = 0; i < N; ++i) {
    //     tree.update(i, vec[i]);
    // }


    // build segment tree in linear N time....

    for(int i = 0 ; i < N; ++i) {
        int in;
        cin >> in;
        vec[i] = in;
    }

    tree.build(vec);

    // queries...
    vector<pair<int, int>> queries = {{0, 1}, {0, 7}, {3, 3}, {4, 4}, {1, 4}, {1, 6}, {5, 7}, {1, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 5}};

    for(int i = 0; i < queries.size(); ++i) {
        auto p = queries[i];

        cout << "( " << p.first << " ," << p.second << " ) : " << tree.get(p.first, p.second) << "\n"; 
    }
    tree.traverse();
    return 0;
}