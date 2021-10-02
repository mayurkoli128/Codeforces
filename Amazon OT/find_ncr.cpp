#include <bits/stdc++.h>
using namespace std ;

long nCr(long n, long r) { 
    if (n < r)
        return 0;
    if (r > n - r) { 
        r = n - r;
    }
    long ans = 1L;
    for (long i = 0; i < r; i++) {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}          
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll test = 1;
    // cin >> test;
    while (test--) {
        int n, r ;
        cin >> n >> r ;
        cout << nCr(n, r) << "\n" ;
    }       
    return 0;
}  


