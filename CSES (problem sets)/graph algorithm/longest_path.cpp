#include <bits/stdc++.h>
#define all(nums)   nums.begin(), nums.end()
using namespace std;
typedef long long int ll;
typedef vector<vector<int>>graph;
const int nx=1e5;
const int imax=INT32_MAX;
const int imin=INT32_MIN;
graph g;
int n, l, r;
pair<int, int>ans={-1, -1};
vector<int>path;

int dfs (int v, int h=0, int p=-1) {
    
    for (int child:g[v]) {
        if (p==child)   continue ;
        dfs (child, h+1, v);
    }
    if (ans.second<h) {
        ans.first=v, ans.second=h;
    }
}
bool find_path(int v, int p=-1) {
    path.push_back (v);
    for (int child : g[v]) {
        if (p==child)   continue ;
        if (find_path (child, v)) return true ;
    }
    if (v==r) {
        return true;
    }
    path.pop_back ();
    return false;
}
int main () {
     ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
    // cin >> t;
    while (t--) {
        cin>>n;
        g.resize(n+1);
        for (int i=0; i<n-1; ++i) {
            int l,r;
            cin>>l>>r;
            g[l].push_back (r);
            g[r].push_back (l);
        }
        // finding two endpoints of longest path in a graph....
        /*
        pt.1 tree is unrooted, tree is undirected 

        first select node x randomly make dfs/bfs call to find the node which is farthest from the node x let say y again make a dfs call for y to find the node which is farthest we have two end points of a longest path now.
        */
        dfs(1);
        l=ans.first, ans={-1, -1};
        dfs(l);
        r=ans.first;
        find_path(l);
        for (int i:path)   cout<<i<<" ";
    }
    return 0;
}