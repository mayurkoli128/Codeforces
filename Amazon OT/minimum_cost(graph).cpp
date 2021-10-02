#include<bits/stdc++.h>
using namespace std ;
typedef vector<vector<pair<int,int>>> graph ;
int main() {
    int n, m ;
    cin >> n >> m ;
    graph g(n) ;

    for (int i=0; i<m; ++i) {
        char a, b ;
        int cost ;
        cin >> a >> b >> cost ;
        g[a-'A'].push_back({b-'A', cost}) ;
        g[b-'A'].push_back({a-'A', cost}) ;
    }
    vector<int>dis(n, INT32_MAX), vis(n), parent(n, -1) ;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq ;
    pq.push({0, 0}) ;
    dis[0] = 0 ;

    while(!pq.empty()) {
        int u = pq.top().second ;
        pq.pop() ;
        vis[u] = 1 ;
        for (auto& adj : g[u]) {
            int v = adj.first, curr_dis = adj.second ;
            if (vis[v] == 0 && dis[v] > curr_dis) {
                dis[v] = curr_dis ;
                parent[v] = u ;
                pq.push({curr_dis, v}) ;
            }
        }
    }
    for (int i=0; i<n; ++i) {
        if (parent[i] != -1) {
            cout << char(i + 'A') << " " << char(parent[i] + 'A') << " " << dis[i] << "\n" ;
        }
    }

    return 0 ;
}