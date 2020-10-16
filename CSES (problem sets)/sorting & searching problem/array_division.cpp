#include <bits/stdc++.h>
#define all(nums) nums.begin(), nums.end()
typedef long long int ll;
const int imax = INT32_MAX;
const int imin = INT32_MIN;
using namespace std;
ll n,k,ans;
vector<ll>nums;
// binary search guessing game technique...

vector<ll> check(ll guess_val) {
    ll msum=0, curr=0, cnt=0;
    for(ll i=0; i<n; ++i) {
        if(curr+nums[i]>guess_val) 
            //count subarray's having sum not greater than guess_val
            cnt++,curr=0;
        curr += nums[i];
        msum=max(msum, curr);
    }
    return {msum, cnt+1};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
    // cin>>t;
    while (t--) {
        cin>>n>>k;
        nums.resize(n);
        for(ll& in:nums)   cin>>in;

        // question (mid)-is it possible to split the array in k subarray's, and after all these numbers we will choose minimum.
        ll l=*max_element(all(nums)), r=accumulate(all(nums), 0ll);
        while (l<=r) {
            ll mid=(l+r)>>1;
            auto res=check(mid);

            // k>=res[1] means still we have a chance to split our array into smaller part (result subarray having minimum sum) to get optimal ans.
            if (k>=res[1]) {
                ans=res[0];
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        cout<<ans;
    }
    return 0;
}
