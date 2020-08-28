#include <bits/stdc++.h>
using namespace std;

int solve (int a, int m) {
    if (m == 0) {
        return 1;
    }
    else if (m & 1) {
        return a*solve (a, m - 1);
    } 
    int val = solve (a, m/2);
    return val * val;
}
int main () {
    int a, m;
    cin >> a >> m;
    cout << solve (a, m);
    return 0;
}