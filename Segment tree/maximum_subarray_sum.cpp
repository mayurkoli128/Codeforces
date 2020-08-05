#include <bits/stdc++.h>
using namespace std;

typedef long long int ln;

struct node {
    ln sum = 0;
    ln prefix_sum = 0;
    ln suffix_sum = 0;
    ln max_sum = 0;
};

vector<ln> vec;
vector<node> segment;
ln size = 1;
ln N, M;

void update_node(ln index) {
    segment[index].sum = segment[index * 2 + 1].sum + segment[index * 2 + 2].sum;
        //initialized sum
        
        //initialized prefix_sum
    segment[index].prefix_sum = max(segment[index * 2 + 1].prefix_sum, segment[index * 2 + 1].sum + segment[index * 2 + 2].prefix_sum);

        //initialized suffix_sum
    segment[index].suffix_sum = max(segment[index * 2 + 1].suffix_sum + segment[index * 2 + 2].sum, segment[index * 2 + 2].suffix_sum);
        
        // initialized max_sum...
    segment[index].max_sum = max(segment[index].sum, 
        max(segment[index * 2 + 1].max_sum, 
        max(segment[index * 2 + 2].max_sum, 
        max(segment[index].prefix_sum, 
        max(segment[index].suffix_sum, segment[index*2 + 1].suffix_sum + segment[index*2 + 2].prefix_sum)))));
    
}

void build(ln l, ln r, ln index) {
    if(l - r == 0) {
        // insertion at leaf node...
        if(N > l)
            segment[index] = {vec[l], vec[l], vec[l], vec[l]};;
        return;
    }

    ln mid = (l + r) >> 1;

    build(l, mid, index*2 + 1);
    build(mid + 1, r, index*2 + 2);

    // creating parent node...
    update_node(index);

    return; 
} 
void update(ln at, ln val, ln l, ln r, ln index) {
    
    if(l - r == 0) {
        segment[index] = {val, val, val, val};
        return;
    }

    ln mid = (l + r) >> 1;
    
    if(mid >= at) {
        update(at, val, l, mid, index*2 + 1);
    } else {
        update(at, val, mid + 1, r, index*2 + 2);
    }
    
    update_node(index);

    return;
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    vec.assign(N, 0);
    while(size < N) {
        size *= 2;
    }
    segment.assign(size*2 - 1, {});

    for(ln i = 0; i < N; ++i) {
        ln in;
        cin >> in;
        vec[i] = in;
    }
    build(0, size - 1, 0);

    int x = segment[0].max_sum;
    if(x < 0) {
            cout << 0 << "\n";
        } else {
            cout << x << "\n";
        }
        
    for(ln i = 0; i < M; ++i) {
        ln index, val;
        cin >> index >> val;
        update(index, val, 0, size - 1, 0);
        int x = segment[0].max_sum;

        if(x < 0) {
            cout << 0 << "\n";
        } else {
            cout << x << "\n";
        }
    }
    return 0;
}
 