// #include <memory.h>
#include <bits/stdc++.h>
#define all(c) (c).begin(), (c).end()
using namespace std;
typedef long long int ll;
typedef unordered_map<ll, ll> umap;
typedef vector<ll> vec;

int max_s (vector<int>& nums, int n) {
    int current = nums[0];
    int max_sum = nums[0];

    for (int i=1; i<n; ++i) {
        current = max(nums[i], current + nums[i]);
        max_sum = max (max_sum, current);
    }
    return max_sum;
}
int solve (vector<vector<int>>& mat, int m, int n) {
   
    int ans = INT32_MIN;
    
    for(int k=0; k<n; ++k) {
        vector<int> temp(m, 0);
        for (int i = k; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                temp[j] += mat[j][i];
            }
            ans = max (ans, max_s(temp, temp.size()));
        }
    }
    return ans;
}
int main () {
    ios :: sync_with_stdio (false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t=1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >>n>>m;
        vector<vector<int>>mat (n, vector<int>(m));

        for (int i=0 ;i<n; ++i) {
            for (int j=0; j<m; ++j) {
                int in;
                cin >> in;
                mat[i][j]=in;
            }
        }  
        cout << solve (mat, n, m)<<"\n"; 
    }

    return 0;
}
