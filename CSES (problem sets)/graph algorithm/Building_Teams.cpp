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
int n,m;
vector<int>color;

// use visited array to not retraverse again a conected component

bool dfs(int v, int c, int parent) {
    vis[v]=true;
    color[v]=c;
    for (int child:g[v]) {
        if (parent==child) continue ;
        // if the node has not colored yet colored it...
        if (color[child]==0)
            if (!dfs (child, 3^c, v)){
                return false;
            }
        // check if the child has colored  make sure it didn't conflict with the color of parent.
        if (color[child]==color[v]) {
            return false;
        }
    }   
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) {
        cin>>n>>m;
        vis.resize(n+1, false);
        g.resize(n+1);
        color.resize(n+1);
        for (int i=0; i<m; ++i) {
            int l,r;
            cin>>l>>r;
            g[l].push_back (r);
            g[r].push_back (l);
        }
        bool flag=true;
        for (int i=1; i<=n; ++i) {
            if (vis[i]) continue;
            // make a dfs for each connected components
                if (!dfs(i, 1, -1)) {
                    flag=false;
                    break;
                }
        }
        if (!flag)  cout<<"IMPOSSIBLE\n";
        else {
            for (int i:color) if(i!=0)  cout<<i<<" ";
        }
    }
    return 0;
}