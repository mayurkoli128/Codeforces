//Assignment operation...

#include <bits/stdc++.h>
using namespace std;

typedef long long ln;
typedef vector<ln> vec;

vec segment(1000005 * 4);
vec lazy(1000005 * 4);
ln size = 1;

// constant time propogation...

void propogate (ln index, ln lx, ln ly) {
    if (lx - ly == 0 || lazy[index] == 0) {
        segment[index] += lazy[index];
        lazy[index] = 0;
        return ;
    }
    ln val = lazy[index];

    lazy[index*2 + 1] += val;
    lazy[index*2 + 2] += val;

    segment[index] += (ly - lx + 1) * val;

    lazy[index] = 0;
    return ;
}
void modify (ln l, ln r, ln val, ln lx, ln ly, ln index) {

    propogate (index, lx, ly);
    
    if (lx > r || ly < l) {
        return ;
    }
    if (lx >= l && ly <= r) {
        lazy[index] += val;
        propogate (index, lx, ly);
        return ;
    }

    ln mid = (lx + ly) >> 1;

    modify (l, r, val, lx, mid, index*2 + 1);
    modify (l, r, val, mid + 1, ly, index*2 + 2);

    segment[index] = segment[index*2 + 1] + segment[index*2 + 2];
}

ln sum (ln l, ln r, ln lx, ln ly, ln index) {
    
    propogate(index, lx, ly);

    if (lx > r || ly < l) {
        return 0;
    }

    if (lx >= l && ly <= r) {
        return segment[index];
    }

     ln mid = (lx + ly) >> 1;

    ln x = sum (l, r, lx, mid, index*2 + 1);
    ln y = sum (l, r, mid + 1, ly, index*2 + 2);

    return x + y;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ln N, M;
    cin >> N >> M;

    while (size < N) {
        size *= 2;
    }

    for (ln i = 0; i < M; ++i) {
        ln c;
        cin >> c;

        if(c == 1) {
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