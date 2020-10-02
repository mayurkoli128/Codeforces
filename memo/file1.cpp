#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<vector<int>>graph;
graph g;
vector<int>nums;
vector<int>dp;
vector<int>parents;

// int bfs(int v, int n) {
//     queue<int>q;
//     int w=0, b=0, ans=0;
//     q.push(v);
//     vector<bool>vis(n+1, false);
//     vis[v]=true;

//     while(!q.empty()) {
//         int n=q.size();

//         for(int i=0; i<n; ++i) {
//             v=q.front();
//             q.pop();
//             nums[v]?w++:b++;
//             ans=max(ans, abs(w-b));
            
//             for(int ele:g[v]) {
//                 if(!vis[ele]) {
//                     q.push(ele);
//                     vis[ele]=true;
//                 }
//             }
//         }
//     }
//     return ans;
// }
void fill(int v, int p) {
    parents[v]=p;

    for(int ele:g[v]) {
        fill(ele, v);
    }
    int curr=nums[v]?1:-1;
    dp[v]=curr;
    if (g[v].empty()) {
        return ;
    }
    int l=dp[g[v][0]];
    int r=g[v].size()>1?dp[g[v][1]]:0;
    
    dp[v]=max(curr, max(max(curr+l, curr+r), curr+l+r));
    return ;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll q=1;
    while (q--) {
        int n;
        cin>>n;
        nums=vector<int>(n+1);
        dp=vector<int>(n+1);
        parents=vector<int>(n+1);
        g.resize(n+1);
        for(int i=1; i<=n; ++i) {
            cin>>nums[i];
        }
        for(int i=0; i<n-1; ++i) {
            int u, v;
            cin>>u>>v;
            g[u].push_back(v);
        }
        fill(1, -1);
        for(int i=1; i<=n; ++i) {
            cout<<dp[i] << " ";
        }
        for(int i=1; i<=n; ++i) {
            // int ans=0, ver=i;
            // int prev=dp[ver];

            // while (ver != -1) {
            //     ans=max(ans, prev);
            //     ver=parents[ver];
            // }
            // cout<<ans<<" ";
        }
        cout<<"\n";
    }
    return 0;
}