// Partition Equal Subset Sum
// subproblem ==>> 

// ask a question to each cell of dp that == > 
// i have ith number so can we make sum sum - vec[i] so that we together can make "SUM"...

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& vec) {
        int size = vec.size();
        
        int sum = accumulate (vec.begin(), vec.end(), 0);
        sum /= 2;
        vector <bool> dp(sum + 1, false);
        dp[0] = true;

        for (int i = 0; i < size; ++i) {
            for (int j = sum; j >= 0; --j) {
                if (j >= vec[i]) {
                    dp[j] = dp[j] || dp[j - vec[i]];
                }
            }
        }
        for (int i = 0; i <= sum; ++i) {
            cout << dp[i] << " ";
        }
        return dp[sum];
    }
};
int main () {
    vector<int> vec =  {1, 5, 11, 5};
    Solution s;
    s.canPartition(vec);
}