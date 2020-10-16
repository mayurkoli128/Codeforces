#include <bits/stdc++.h>
#define all(nums) nums.begin(), nums.end()
typedef long long int ll;
const int imax = INT32_MAX;
const int imin = INT32_MIN;
using namespace std;
const int mx = 2*10e5 + 10;
typedef vector<vector<int>>graph;
graph g;
vector<int>dp;
void dfs(int v=1) {
    dp[v]=1;
    for (int ele:g[v]) {
        dfs(ele);
        dp[v]+=dp[ele];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    // cin>>t;
    while (t--) {
        int n;
        cin>>n;
        g.resize(n+1);
        dp.resize(n+1);
        for (int i=2; i<=n; ++i) {
            int in;
            cin>>in;
            g[in].push_back(i);
        } 
        dfs();
        for(int i=1; i<=n; ++i) {
            cout<<dp[i]-1<<" ";
        }
    }
    return 0;
}
