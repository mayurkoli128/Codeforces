#include <bits/stdc++.h>
#define all(nums) nums.begin(), nums.end()
typedef long long int ll;
const int imax = INT32_MAX;
const int imin = INT32_MIN;
using namespace std;
ll n,ans;
vector<ll>nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
    // cin>>t;
    while (t--) {
        cin>>n;
        nums.resize(n);
        for(ll& in:nums)   cin>>in;
        unordered_map<ll, int>umap;
        
        //prefix sum can also be the possible ans which is evenly divisible by k
        umap[0]++;
        ll curr_sum=0, ans=0;
        for (int i=0; i<n; ++i) {
            curr_sum+=nums[i];

            // substract extra adddon which is curr_sum%n in order to get the sum divisible by n
            // carefull! the nums array containe negative numbers ass well so...
            // we use moduler arithmetic for negative number's
            ans += umap[((curr_sum%n)+n)%n]++;
        }
        cout<<ans;
    }
    return 0;
}
