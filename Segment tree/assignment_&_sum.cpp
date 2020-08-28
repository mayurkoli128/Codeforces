#include <bits/stdc++.h>
using namespace std;

typedef long long ln;
typedef vector<ln> vec;
vec lazy (1000005*4);
vec segment (1000005*4);
ln size = 1;
const ln NO_OPEARATION = INT32_MAX;

void propogate (ln index, ln lx, ln ly) {
    if (lx - ly == 0 || lazy[index] == NO_OPEARATION) {
        return ;
    }
    lazy[index*2 + 1] = lazy[index];
    lazy[index*2 + 2] = lazy[index];
    
    ln mid = (lx + ly) >> 1;

    segment[index*2 + 1] = (mid - lx + 1) * lazy[index];
    segment[index*2 + 2] = (ly - mid) * lazy[index];
    lazy[index] = NO_OPEARATION;
}
void modify (ln l, ln r, ln val, ln lx, ln ly, ln index) {
    if (l > ly || r < lx) {
        return ;
    }
    if (l <= lx && r >= ly) {
        // assignment oparation...
        lazy[index] = val;
        segment[index] = (ly - lx + 1) * val;
        return ;
    }
    propogate (index, lx, ly);

    ln mid = (lx + ly) >> 1;

    modify (l, r, val, lx, mid, index * 2 + 1);
    modify (l, r, val, mid + 1, ly, index * 2 + 2);
    segment[index] = segment[index*2 + 1] + segment[index*2 + 2];

    return ;
}
ln sum (ln l, ln r, ln lx, ln ly, ln index) {
    propogate (index, lx, ly);
    
    if (l > ly || r < lx) {
        return 0;
    }
    if (l <= lx && r >= ly) {
        return segment[index];
    }

    ln mid = (lx + ly) >> 1;

    ln x = sum (l, r, lx, mid, index * 2 + 1);
    ln y = sum (l, r, mid + 1, ly, index * 2 + 2);
    
    return x + y;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ln N, M;
    cin >> N >> M;

    while (size < N) {
        size *= 2;
    }

    for (ln i = 0; i < M; ++i) {
        ln c;
        cin >> c;
        if (c == 1) {
            ln l, r, v;
            cin >> l >> r >> v;
            modify (l, r - 1, v, 0, size - 1, 0);

        } else {
            ln l, r;
            cin >> l >> r;
            cout << sum (l, r - 1, 0, size - 1, 0) << "\n";
        }
    }
    return 0;
}