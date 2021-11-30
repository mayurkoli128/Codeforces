#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define all(nums) nums.begin(), nums.end()
#define allr(nums) nums.rbegin(), nums.rend()
#define len(a) int((a).size())
typedef long long int ll;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>ordered_set ;
typedef vector<vector<pair<int,double>>> graph;
const int inf = INT32_MAX;
const int minf = INT32_MIN;
template<class T>T cal(T n) {return (n*1ll*(n+1))/2;}
template<class T>T mx(T begin, T end){return max_element(begin, end);}
template<class T>T mn(T begin, T end){return min_element(begin, end);}
template<class T>void getUnique(vector<T>& nums){sort(nums.begin(), nums.end()); nums.erase(unique(nums.begin(), nums.end()), nums.end());}
template<class T>void print(vector<T>nums){for(T i:nums)cout<<i<<" ";cout<<"\n";}
template<class T>void read(vector<T>&nums){for(T& i:nums)cin>>i;}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll test = 1;
    // cin >> test;
    while (test--) {
        // int n ;
        // cin >> n ;
        // vector<int>nums(n) ;
        // read(nums) ;
        print(getTimeStamps({0,0,1,5}, {0,1,1,0})) ;
        print(getTimeStamps({0,1,1,3,3}, {0,1,0,0,1})) ;
    }
    return 0;
}  


