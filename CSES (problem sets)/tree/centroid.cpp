#include <bits/stdc++.h>
#define all(nums) nums.begin(), nums.end()
#define allr(nums) nums.rbegin(), nums.rend()
using namespace std;
typedef long long int ll;
typedef vector<vector<int>>graph;
const int imax = INT32_MAX;
const int imin = INT32_MIN;
const int mx=3e5;
const ll inf=1e18;
template<class T>void print(vector<T>vec){for(T i:vec)cout<<i<<" ";cout<<"\n";}
template<class T>void alloc(vector<vector<T>*>vec, T n){for(auto v:vec)v->resize(n+1);}

// there are at most only 2 centroids are possible for tree
graph g;
vector<int>dp, centroids;
int n;

void dfs(int v, int p) {
	dp[v]=1;
	bool is_centroid=true;
	for (int child:g[v]) {
		if (child==p)	continue ;
		dfs(child, v);
		dp[v] += dp[child];
		if (dp[child]>n/2)	is_centroid=false;
	}
	if (n-dp[v]>n/2) {
		is_centroid=false;
	}
	if (is_centroid)	centroids.push_back(v);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    // cin>>t;
    while(t--) {
		cin>>n;
		g.resize(n+1);
		dp.resize(n+1);
		for (int i=0; i<n-1; ++i) {
			int u, v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 0);
		print(centroids);
    }
    return 0;
}