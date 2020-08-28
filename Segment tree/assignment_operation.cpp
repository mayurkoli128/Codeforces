//Assignment operation in range (non commutative operation)...

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef long long ln;

vec segment(1000005 * 4);
int size = 1;
const int NO_OPEARATION = INT32_MAX;

void propogate(int index, int lx, int ly) {
    if (lx - ly == 0 || segment[index] == NO_OPEARATION)   return ;

    segment[index*2 + 1] = segment[index];
    segment[index*2 + 2] = segment[index];
    segment[index] = NO_OPEARATION;
}
void modify (int l, int r, int val, int lx, int ly, int index) {
    
    if (lx > r || ly < l) return ;

    if (l <= lx && r >= ly) {
        // assigment...
        segment[index] = val;
        return ;
    } 
    propogate(index, lx, ly);
    int mid = (lx + ly) >> 1;

    modify (l, r, val, lx, mid, index*2 + 1);
    modify (l, r, val, mid + 1, ly, index*2 + 2);

}
int get (int i, int lx, int ly, int index) {
    if (lx - ly == 0) {
        return segment[index];
    }
    int mid = (lx + ly) >> 1;

    int res;
    if (mid >= i) {
        res = get (i, lx, mid, index*2 + 1);
    } else {
        res = get (i, mid + 1, ly, index*2 + 2);
    }
    if (segment[index] == NO_OPEARATION) {
        return res;
    }
    return segment[index];
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    while (size < N) {
        size *= 2;
    }

    for (int i = 0; i < M; ++i) {
        int c;
        cin >> c;

        if(c == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            modify (l, r - 1, v, 0, size - 1, 0);
        } else {
            int i;
            cin >> i;
            cout << get (i, 0, size - 1, 0) << "\n";
        }
    }

    return 0;
}