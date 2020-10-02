#include <bits/stdc++.h>
#define all(nums) nums.begin(), nums.end();
typedef long long int ll;
const int imax = INT32_MAX;
const int imin = INT32_MIN;
using namespace std;
const int mx = 10e5 + 10;

ll solve(vector<ll>& nums, ll m) {
    ll sum=0;
    for(ll i=0; i<nums.size(); ++i) {
        sum += abs(m-nums[i]);
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    // cin>>t;
    while (t--) {
        ll n;
        cin>>n;
        vector<ll>nums(n);
        for(ll& in:nums)   cin>>in;
        sort(nums.begin(), nums.end());
        ll median=nums[n/2];
        cout<<solve(nums,median)<<"\n";
    }
    return 0;
}
