#include <bits/stdc++.h>
using namespace std;

int ub(int left, int right, int val, vector<int>& nums) {

    int l = left, r = right ;
    while(l <= r) {
        int mid = (l + r) >> 1 ;
        if (nums[mid] > val) {
            r = mid-1 ;
        } else {
            l = mid+1 ;
        }
    }
    return l ;
}
int main() {
    int n, k ;
    cin >> n >> k ;
    vector<int>nums(n) ;
    for(int& in : nums) {
        cin >> in ;
    }
    sort(nums.begin(), nums.end()) ;
    int mx = 0 ;
    for (int i=1; i<n; ++i) {
        int ind = ub(0, i-1, k - nums[i], nums) ;
        if (ind != 0) {
            ind-- ;
            if (mx < nums[i] + nums[ind]) {
                cout << ind << ' ' << i << '\n' ;
                mx = nums[i] + nums[ind] ;
            }
        }        
    }

    return 0 ;
}
