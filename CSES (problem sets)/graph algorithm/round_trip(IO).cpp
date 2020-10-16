//leetcode....

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>>graph, edges;
#define all(nums)   nums.begin(), nums.end()

// find cycle and print it...using in and out time...
class Solution {
graph g;
vector<bool>vis;
vector<int>cycle, tin, low;
int timer, flag=0;
public:
    Solution():timer(0){}
    void dfs (int v, int p=-1) {
        vis[v]=true;
        tin[v]=low[v]=timer++;
        for (int adj:g[v]) {
            if (p==adj||flag) continue ;
            if (vis[adj]) {
                cycle.push_back (adj);
                cycle.push_back (v);
                low[v]=min (low[v], tin[adj]);
                flag=1;
            } else {
                dfs(adj, v);
                if (tin[v]>=low[adj]) {
                    cycle.push_back (v);
                }
                low[v]=min (low[v], low[adj]);
            }
        }
    }
    void build_graph(int n, edges e) {
        g.resize(n+1);
        vis.resize(n+1);
        tin.resize(n+1);
        low.resize(n+1);
        for (int i=0; i<e.size(); ++i) {
            g[e[i][0]].push_back(e[i][1]);
            g[e[i][1]].push_back(e[i][0]);
        }
    }
    void findCycle(int n, edges& e) {
        build_graph(n, e);
        for (int i=1; i<=n; ++i) {
            if (vis[i]) continue ;
            dfs(i);
            if (cycle.size())   break;
        }
        if (cycle.empty()) {
            cout<<"IMPOSSIBLE";
            return ;
        }
        cout<<cycle.size()<<"\n";
        for (int i:cycle)   cout<<i<<" ";
    }
};
int main () {
    Solution s;
    int n,m;
    cin>>n>>m;
    edges e;
    for (int i=0; i<m; ++i) {
        int l,r;
        cin>>l>>r;
        e.push_back({l, r});
    }
    s.findCycle(n, e);
}