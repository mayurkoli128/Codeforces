#include<bits/stdc++.h>
using namespace std ;
int MOD = 1e9 + 7 ;

set<string>pre ;
int dp[200000] ;
int solve(int in, string& s) {
    int n = s.size() ;
    if (in == n) {
        return 1 ;
    }
    int& curr = dp[in] ;
    if (curr != -1) return curr ;
    int ans = 0 ;
    for (int i=1; i<=6; ++i) {
        if (n - in < i) break ;
        string curr = s.substr(in, i) ;
        if (pre.count(curr)) {
            ans = (ans + solve(in+i, s))%MOD ;
        }
    }
    return curr = ans ;
}
int main() {
    string s ;
    cin >> s ;
    memset(dp, -1, sizeof(dp)) ;
    for (int i=2; i<=1e6; ++i) {
        int flag = 1 ;
        for (int j=2; j*j<=i; ++j) {
            if (i % j == 0) {
                flag = 0 ;
                break ;
            }
        }
        if (flag)   pre.insert(to_string(i)) ;
    }
    cout << solve(0, s) ;
    return 0 ;
}