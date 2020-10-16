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

void bfs() {
    queue<int>q;
    vector<int>p(n+1);
    q.push(1);
    vis[1]=true;
    p[1]=-1;
    bool flag=true;
    while (!q.empty()) {
        int top=q.front();
        if (top==n) {
            flag=false;
        }
        q.pop();
        for (int adj:g[top]) {
            if (vis[adj])   continue;
            q.push(adj);
            p[adj]=top;
            vis[adj]=true;
        }
    }
    // retrive path....
    if (flag)  { cout<<"IMPOSSIBLE";return;}
    int node=n;
    vector<int>ans;
    while (node != -1) {
        ans.push_back (node);
        node=p[node];
    }
    cout<<ans.size()<<"\n";
    for (int i=ans.size()-1; i>=0; --i) cout<<ans[i]<<" ";
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
        vector<int>c;
        for (int i=0; i<m; ++i) {
            int l,r;
            cin>>l>>r;
            g[l].push_back (r);
            g[r].push_back (l);
        }
        bfs();
    }
    return 0;
}