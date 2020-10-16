#include <bits/stdc++.h>
#define all(nums) nums.begin(), nums.end()
typedef long long int ll;
const int imax = INT32_MAX;
const int imin = INT32_MIN;
using namespace std;
const int mx = 2*10e5 + 10;
typedef vector<vector<int>>graph;
graph g;
vector<vector<int>>dp;
int ans=0;

void dfs(int v=1, int parent=0) {
    bool leaf=true;
    vector<int>pref, suff;

    for (int child:g[v]) {
        if (child == parent)    continue ;
        leaf=false;
        dfs (child, v);
        int val=max (dp[child][1], dp[child][0]);
        pref.push_back (val);
        suff.push_back (val);
    }
    if (leaf)   return ;   
    int n=pref.size();
    
    for (int i=1; i<n; ++i) {
        pref[i] += pref[i-1];
    }
    for (int i=n-2; i>=0; --i) {
        suff[i] += suff[i+1];
    }
    dp[v][0]=suff[0];
    int temp=0,ii=0;
    for (int child:g[v]) {
        if (child == parent)    continue ;
        int lval=ii?pref[ii-1]:0;
        int rval=(ii!=n-1 ? suff[ii+1]:0);
        temp=max(temp, 1+lval+rval+dp[child][0]);
        ++ii;
    }
    dp[v][1]=temp;
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
        dp.resize(n+1, vector<int>(2));
        for (int i=1; i<n; ++i) {
            int u, v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        } 
        dfs();
        cout<<max(dp[1][1], dp[1][0]);
    }
    return 0;
}
