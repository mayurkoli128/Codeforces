#include <bits/stdc++.h>
#define all(nums) nums.begin(), nums.end()
#define allr(nums) nums.rbegin(), nums.rend()
#define block 555
using namespace std;
typedef long long int ll;
typedef vector<vector<int>>graph;
const int imax = INT32_MAX;
const int imin = INT32_MIN;
const int mx=1e9;
const ll inf=1e18;
template<class T>void print(vector<T>vec){for(T i:vec)cout<<i<<"\n";cout<<"";}
template<class T>void alloc(vector<vector<T>*>vec, T n){for(auto v:vec)v->resize(n+1);}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    // cin>>t;
    while(t--) {
        string s,t;
        cin>>s>>t;
        int m=s.size(), n=t.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        for (int i=0; i<=m; ++i)    dp[0][i]=1;

        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=m; ++j) {
                if (s[j-1]==t[i-1]) {
                    dp[i][j] = dp[i][j-1]+dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        cout<<dp[n][m];
	}
    return 0;
}