#include <bits/stdc++.h>
#define all(nums) nums.begin(), nums.end();
typedef long long int ll;
const int imax = INT32_MAX;
const int imin = INT32_MIN;
using namespace std;
const int mx = 10e5 + 10;
 
// 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    // cin>>t;
    while (t--) {
        int n,x;
        cin>>n>>x;
        vector<int>nums(n);
        for(int& in:nums)   cin>>in;
        int l=0, r=n-1;
        int cnt=0;
        sort(nums.begin(), nums.end());
        // 7 2 3 9
        // 2 3 7 9
        while (l<=r) {
            if (nums[r]+nums[l]<=x) {
                cnt++;
                l++; r--;
            } else if (nums[r]<=x){
                cnt++;
                r--;
            } else {
                l++;
            }
        }
        cout<<cnt;
    }
    return 0;
}