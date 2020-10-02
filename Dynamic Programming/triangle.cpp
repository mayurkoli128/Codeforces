#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper (vector<vector<int>>& triangle, int index, int adj_index,vector<vector<int>>& dp) {
        int m=triangle.size();
        
        if (m <= index || adj_index >= index+1) {
            return 0;
        }
        int val = triangle[index][adj_index];
        
        if (dp[index][adj_index]) {
            return dp[index][adj_index] ;
        }
        
        dp[index][adj_index] = min (val + helper (triangle, index+1, adj_index, dp), val + helper (triangle, index+1, adj_index+1, dp));
        return dp[index][adj_index] ;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));
        return helper (triangle, 0, 0, dp);
    }
};
// in linear space current element result is only depend on next row so,...
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp (n);
        
        for (int i=n-1; i>=0; --i) {
            for (int j=0; j<=i; ++j) {
                if (i == n-1) {
                    dp[j]=triangle[i][j];
                    continue ;
                }
                dp[j] = triangle[i][j]+min (dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};
int main () {

}