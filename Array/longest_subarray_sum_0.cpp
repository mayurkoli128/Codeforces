#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> nums;
typedef vector<vector<char>> vec;

int solve (vector<int>& nums) {
    unordered_map<int, int>umap;
    int sum = 0, ans = 0;

    for (int i=0; i<nums.size(); ++i) {
        sum += nums[i];
        if (sum == 0) {
            ans = max(ans, i+1);
        }
        if (umap.find (sum)!=umap.end()) {
            ans = max (ans, i-umap[sum]+1);
        } else {
            umap[sum]=i;
        }
    }
    return ans;
}
int main() {
    int t=1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> vec (n);

        for (int i=0; i<n; ++i) {
            int in;cin>>in;
            vec[i]=in;
        }
        cout << solve (vec);
    }
}