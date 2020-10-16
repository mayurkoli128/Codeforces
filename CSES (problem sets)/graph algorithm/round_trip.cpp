#include <bits/stdc++.h>
#define all(nums)   nums.begin(), nums.end()
using namespace std;
typedef long long int ll;
typedef vector<vector<int>>graph;
typedef unordered_map<int, bool>umap;
graph g;
vector<bool>vis;
vector<int>parent;
int start=-1, endd=-1;
 
bool dfs (int v, int p) {
    vis[v]=true;
    parent[v]=p;
 
    for (int child:g[v]) {
        if (child==p)  continue ;
        if (vis[child]) {
            start=child;
            endd=v;
            return true;
        }
        if (dfs (child, v)) {
            return true;
        }
    }
    return false;
}
int main () {
     ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
    // cin >> t;
    while (t--) {
        int n, m;
        cin>>n>>m;
        g.resize(n+1);
        vis.resize(n+1);
        parent.resize(n+1);
        for (int i=0; i<m; ++i) {
            int l, r;
            cin>>l>>r;
            g[l].push_back (r);
            g[r].push_back (l);
        }
        bool flag=false;
        for (int i=1; i<=n; ++i) {
            if (vis[i]) continue ;
            if (dfs(i, -1)) {flag=true; break ;}
        }
        if (!flag) {
            cout<<"IMPOSSIBLE\n";
            continue ;
        }
        vector<int>cycle={start};
        while (start != endd) {
            cycle.push_back (endd);
            endd=parent[endd];
        }
        reverse(all(cycle));
        cout<<cycle.size()+1<<"\n";
        cout<<start<<" ";
        for (int v:cycle)   cout<<v<<" ";
    }
    return 0;
}