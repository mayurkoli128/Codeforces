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
int ans=0;
 
void dfs(int v=1, int parent=-1) {
    vector<int>child_dia;
    bool leaf=true;
    dp[v]=1;
    for (int ele:g[v]) {
        if (parent==ele) continue  ;
        leaf=0;
        dfs(ele, v);
        child_dia.push_back(dp[ele]);
    }
    if (leaf)   return ;
 
    // complete operation for non leaf node
    sort (all(child_dia), greater<int>());
    int size=child_dia.size();
    int val=child_dia[0]+(size>1 ? child_dia[1]:0);
    ans=max (ans, 1+val);
    dp[v]=1+*max_element(all(child_dia));
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
        for (int i=1; i<n; ++i) {
            int u, v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        } 
        dfs();
        cout<<(ans?ans-1:0);
    }
    return 0;
}