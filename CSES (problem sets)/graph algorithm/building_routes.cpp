#include <bits/stdc++.h>
#define all(nums) nums.begin(), nums.end()
typedef long long int ll;
const int imax = INT32_MAX;
const int imin = INT32_MIN;
using namespace std;
const int mx = 10e5 + 10;
const long MOD=1e9+7;
vector<vector<int>>g;
vector<bool>vis;

void dfs(int v) {
    vis[v]=true;
    for (int child:g[v]) {
        if (!vis[child]) 
            dfs(child);
    }
} 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vis.resize(n+1, false);
        g.resize(n+1);
        vector<int>c;
        for (int i=0; i<m; ++i) {
            int l,r;
            cin>>l>>r;
            g[l].push_back (r);
            g[r].push_back (l);
        }
        for (int i=1; i<=n; ++i) {
            if (!vis[i]) {
                c.push_back (i);
                dfs(i); 
            }       
        }
        int len=c.size();
        cout<<len-1<<"\n";
        for (int i=1; i<len; ++i) {
            cout<<c[i]<<" "<<c[i-1]<<"\n";
        }
    }
    return 0;
}