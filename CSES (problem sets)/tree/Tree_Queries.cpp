#include <bits/stdc++.h>
#define all(nums)   nums.begin(), nums.end()
using namespace std;
typedef long long int ll;
typedef vector<vector<int>>graph;
typedef unordered_map<int, bool>umap;
vector<int>parent;
vector<int>depth;
vector<int>tin, tout;
int T;
graph g;

// using INTIME/OUTTIME technique to find whether the nodes are in same path or not from root to lagest depth node.

//INTIME:when we visit the node first time, OUTTIME: when we visit the node again.

void dfs1(int v, int cur_depth, int p=-1) {
    parent[v]=p;
    depth[v]=cur_depth;
    tin[v]=T++;
    for(int ele:g[v]) {
        if (p == ele)   continue;
        dfs1(ele, cur_depth+1, v);
    }
    tout[v]=T++;
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
        parent.resize(n+1);
        depth.resize(n+1);
        tin.resize(n+1);
        tout.resize(n+1);

        for(int i=0; i<n-1; ++i) {
            int l, r;
            cin>>l>>r;
            g[l].push_back(r);
            g[r].push_back(l);
        }
        dfs1(1, 0);
        while(m--) {
            int k;
            cin>>k;
            vector<int>q(k);
            for(int& in:q) {
                cin>>in;
                if (in==1)  continue ;
                in=parent[in];
            }
            auto lamda=[](int a, int b) {
                return depth[a]<depth[b];
            };
            int node=*max_element(all(q), lamda);

            int intime=tin[node], outtime=tout[node];
            bool flag=true;
            for (int v:q) {
                if (intime>=tin[v]&&outtime<=tout[v]) {
                    continue ;
                } 
                flag=false;
                break ;
            }
            if(flag) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }   
    return 0;
}