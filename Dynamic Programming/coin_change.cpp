// minimum number of coins to make change...
typedef int ln;

#include <bits/stdc++.h>
using namespace std;

// Bottom-up approach
ln solve(int* denominations, int change, int n, vector<vector<ln>>& umap, ln tempChange) {

    if(n < 0 || change < 0)   return tempChange;

    if(umap[n][change]) return umap[n][change];

    if(change == 0) {
        return 0;
    }
    // select the coin...
    umap[n][change] = min(1 + solve(denominations, change - denominations[n], n, umap, tempChange), solve(denominations, change, n - 1, umap, tempChange));

    return umap[n][change];
}
// TOp Down Approach..

int solve(int* denominations, int change, int n) {
    vector<int> arr(change + 1, 0);

    arr[0] = 0;
    for(int i = 1; i <= change; ++i) {
        arr[i] = change;
    }

    for(int i = 1; i <= change; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i >= denominations[j])
                arr[i] = min(1 + arr[i - denominations[j]], arr[i]);
        }
    }
    return arr[change];
}
// change 11 
// 1, 2, 5

// 0 1  2  3  4  5  6  7  8  9  10 11
// 0 12 12 12 12 12 12 12 12 12 12 12

int main() {
    int denominations[] = {2, 5, 1};
    int change = 20;
    int size = sizeof(denominations) / sizeof(int);
    vector<vector<ln>> umap(size, vector<ln>(change + 1, 0));

    cout << solve(denominations, change, size - 1, umap, change) << " ";
    cout << solve(denominations, change, size);
    
    return 0;
}