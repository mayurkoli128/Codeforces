#include <bits/stdc++.h>
#define all(nums) nums.begin(), nums.end()
#define allr(nums) nums.rbegin(), nums.rend()
using namespace std;
typedef long long int ll;
typedef vector<vector<int>>graph;
const int imax = INT32_MAX;
const int imin = INT32_MIN;
const int mx=1e9;
const ll inf=1e18;
ll sn(ll n) {return (n*1ll*(n-1))/2;}
template<class T>void print(vector<T>vec){for(T i:vec)cout<<i<<" ";cout<<"\n";}
template<class T>void alloc(vector<vector<T>*>vec, T n){for(auto v:vec)v->resize(n+1);}


// PROBLEM :  Given a tree T of N nodes, where each node i has Ci coins attached with it. You have to choose a subset of nodes such that no two adjacent nodes(i.e. nodes connected directly by an edge) are chosen and sum of coins attached with nodes in chosen subset is maximum.
graph g;
vector<int>coins, dp1, dp2;

void dfs (int v, int p) {
	int sum1=0, sum2=0;
	for (int child:g[v]) {
		if (child==p)	continue ;
		dfs (child, v);
		// calculation..
		sum1 += dp2[child];
		sum2 += max(dp1[child], dp2[child]);
	}
	// dp1 =>choose vertex v
	// dp2 =>don't choose vertex v
	dp1[v]=coins[v]+sum1; 
	dp2[v]=sum2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    // cin>>t;
    while(t--) {
		int n;
		cin>>n;
		g.resize(n+1);
		alloc({&dp1, &dp2, &coins}, n);
		for (int i=1; i<=n; ++i)	cin>>coins[i];
		for (int i=0; i<n-1; ++i) {
			int u, v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, -1);
		cout<<max(dp1[1], dp2[1])<<"\n";
	}
    return 0;
}
