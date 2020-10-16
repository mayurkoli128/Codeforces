#include <bits/stdc++.h>
#define all(nums)   nums.begin(), nums.end()
using namespace std;
typedef long long int ll;
typedef vector<vector<int>>graph;
const int nx=1e5;
const int imax=INT32_MAX;
const int imin=INT32_MIN;
graph g;
int n, m, timer=1;

vector<int>vis, tin, low;
vector<vector<int>>ans;

void dfs (int v, int p=-1) {
    low[v]=tin[v]=timer++;
    vis[v]=true;
    for (int adj:g[v]) {
        if (adj==p) continue ;
        if (vis[adj]) {
            // replace low time of v with minimum intime of adj vertex.
            low[v]=min (tin[adj], low[v]);
        } else {
            dfs(adj, v);
            // check if there is any adj vertex having lowtime(adj) > intime(v) 
            if (tin[v]<low[adj]) {
                vector<int> vv={v, adj};
                sort(all(vv));
                ans.push_back (vv);
            }
            low[v]=min (low[adj], low[v]);
        }
    }
}
int main () {
     ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
    // cin >> t;
    while (t--) {
        cin>>n>>m;
        vis.resize(n+1);
        g.resize(n+1);
        tin.resize(n+1,-1);
        low.resize(n+1,-1);
        for (int i=0; i<m; ++i) {
            int l,r;
            cin>>l>>r;
            g[l].push_back (r);
            g[r].push_back (l);
        }
        
        // make dfs for all connected component's
        for (int i=1; i<=n; ++i) {
            if (vis[i]) continue ;
            dfs (i);
        }
        cout<<ans.size()<<"\n";
        sort (all(ans));
        for(auto ele:ans) {
            cout<<ele[0]<<" - "<<ele[1]<<"\n";
        }
    }
    return 0;
}
/*
TC:
3

5 4
1 2
4 2
2 3
4 5

5 5
1 2
1 3
3 2
3 4
5 4

4 6
1 3
1 4
2 1
3 2
4 2
4 3
Caso #1
4
1 2
2 3
2 4
4 5
Caso #2
2
3 4
4 5
Caso #3
Sin bloqueos

*/