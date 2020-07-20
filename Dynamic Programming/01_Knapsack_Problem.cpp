#include <bits/stdc++.h>
#define MAX 500
using namespace std;

// Top Down
int knapSack(int w, int weight[], int price[], int n) 
{ 
    
    int dp[n + 1][w + 1] = {{0}};
    
    for (int i = 0; i <= n; ++i)
    {
    	for (int wt = 0; wt <= w; ++wt)
    	{
    		if(i == 0 || wt == 0) {
    			dp[i][wt] = 0;
    			continue;
    		}
    		else if(weight[i-1] <= wt){
    			dp[i][wt] = max(price[i-1] + dp[i-1][wt - weight[i-1]], dp[i-1][wt]);
    		}
    		else if(weight[i-1] > wt){
    			dp[i][wt] = dp[i - 1][wt];
    		}
    	}
    }
    return dp[n][w];

}
// Bottom up...

int knapSack(int* weight, int* price, int n, int w, int (*memo)[MAX]) {
    if(n < 0 || w == 0) {
        return 0;
    }
    if(memo[n][w] != -1)    return memo[n][w];

    // string key = to_String(n) + '|' + to_string(w);

    if(weight[n] > w) {
        memo[n][w] = knapSack(weight, price, n - 1, w, memo);
        return memo[n][w];
    }

    memo[n][w] = max(price[n] + knapSack(weight, price, n - 1, w - weight[n], memo), knapSack(weight, price, n - 1, w, memo));

    return memo[n][w];
}
int main() {
    int weight[] = {4, 2, 7, 8, 9, 10};
    int price[] = {1, 2, 3, 6, 7, 8};
    int w = 2;
    int n = 4;
    
    cout << knapSack(w, weight, price, n) << " ";
    int memo[MAX][MAX];

    memset(memo, -1, sizeof(memo));
    cout << knapSack(weight, price, n - 1, w, memo);

    return 0;
}
