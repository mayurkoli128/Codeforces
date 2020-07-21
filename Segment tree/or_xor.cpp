// alternate Xor and Or...

#include <iostream>
#include <vector>
typedef long long int ln;
using namespace std;

class seg_tree {
private:
    vector<ln> segment;
    ln size;

    void build(vector<ln>& vec, ln index, ln lx, ln rx, ln level) {
        if(lx - rx == 0) {
            if(lx < size)
                segment[index] = vec[lx];
            return;
        }
        ln mid = lx - (lx - rx) / 2;

        build(vec, index*2 + 1, lx, mid, level + 1);
        build(vec, index*2 + 2, mid + 1, rx, level + 1);

        if(level & 1)
            segment[index] = (segment[index*2 + 1] ^ segment[index*2 + 2]);
        else 
            segment[index] = (segment[index*2 + 1] | segment[index*2 + 2]);
        
        return;
    }
    void set(ln at, ln val, ln index, ln lx, ln rx, ln level) {
        if(lx - rx == 0) {
            segment[index] = val;
            return;
        }

        ln mid = lx - (lx - rx) / 2;

        if(at <= mid)
            set(at, val, index*2 + 1, lx, mid, level + 1);
        else
            set(at, val, index*2 + 2, mid + 1, rx, level + 1);

        if(level & 1)
            segment[index] = (segment[index*2 + 1] ^ segment[index*2 + 2]);
        else 
            segment[index] = (segment[index*2 + 1] | segment[index*2 + 2]);
        
        return;
    }
    // void traverse(ln index) {

    //     if(index >= size*2 - 1) return ;

    //     cout << segment[index] << " ";

    //     traverse(index*2 + 1);
    //     traverse(index*2 + 2);

    //     return ;
    // }
public:
    seg_tree(ln n) {
        size = n;
        segment.assign(size*2 - 1, 0LL);        
    }
    void build(vector<ln>& vec, ln N) {
        
        build(vec, 0, 0, size - 1, (N + 1) & 1);
    }
    void set(ln at, ln val, ln N) {
        set(at, val, 0, 0, size - 1, (N + 1) & 1);
    }
    ln query_action() {
        return segment[0];
    }
    // void traverse() {
    //     traverse(0);
    // }
};

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    ln N, M;
    cin >> N >> M;

    ln itr = (1 << N);
    vector<ln> vec(itr);

    seg_tree tree(itr);

    for(ln i = 0; i < itr; ++i) {
        ln in;
        cin >> in;
        vec[i] = in;
    }
    tree.build(vec, N);
    // tree.traverse();

    for(ln i = 0; i < M; ++i) {
        ln p, val;
        cin >> p >> val; 
        tree.set((p - 1), val, N);
        cout << tree.query_action() << "\n";
    }
    return 0;
}