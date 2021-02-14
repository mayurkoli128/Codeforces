#include <bits/stdc++.h>
#define all(nums) nums.begin(), nums.end()
#define allr(nums) nums.rbegin(), nums.rend()
#define len(a) int((a).size())
using namespace std;
typedef long long int ll;
typedef std::vector<vector<int>>graph;
typedef std::pair<int, int>pp;
const int imax = INT32_MAX;
const int imin = INT32_MIN;
const ll inf=1e18;
const ll MOD=1e9+7;
const ll range=1e6;
graph g;
template<class T>T cal(T n) {return n*1ll*(n-1)*(n-2)/6;}
template<class T>T mx(T begin, T end){return max_element(begin, end);}
template<class T>T mn(T begin, T end){return min_element(begin, end);}
template<class T>T fact(T n){ll res=1;for (ll i=2; i<=n; ++i) {res*=i*1LL;}return res;}
template<class T>void getUnique(vector<T>& nums){sort(nums.begin(), nums.end()); nums.erase(unique(nums.begin(), nums.end()), nums.end());}
template<class T>void print(vector<T>nums){for(T i:nums)cout<<i<<" ";cout<<"\n";}
template<class T>void read(vector<T>&nums){for(T& i:nums)cin>>i;}
template<class T>void fre(vector<T>&a, vector<T>nums){for(T ele:nums)a[ele]++;}

vector<vector<int>>parent;
vector<int>dis;
void dfs(int v, int p=0) {
    parent[v][0]=p;
    for (int child:g[v]) {
        if (p==child) continue;
        dis[child] = 1+dis[v];
        dfs(child, v);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    cin>>t;
    for (int test=1; test<=t; ++test) {
        parent.clear();
        dis.clear();
        cout<<"case "<<test<<":\n";
        int n, m;
        cin>>n;
        g.resize(n+1);
        dis.resize(n+1);
        parent.resize(n+1, vector<int>(100, 0));
        for (int i=1; i<=n; ++i) {
            int len;
            cin>>len;
            for (int j=1; j<=len; ++j) {
                int node;
                cin>>node;
                g[i].push_back(node);
                g[node].push_back(i);
            }
        }
        dfs(1);
        for (int i=1; i<=n; ++i) {
            int node = i;
            for (int j=1; j<100; ++j) {
                parent[i][j] = parent[node][0];
                node = parent[i][j];
            }
        }
        int q;
        cin>>q;
        while (q--) {
            int l, r;
            cin>>l>>r;
            while (l != r) {
                int d=dis[l]-dis[r];
                if (d<0)    swap(l, r);
                l=parent[l][0];
            }
            cout<<l<<"\n";
        }
    }       
    return 0;
}