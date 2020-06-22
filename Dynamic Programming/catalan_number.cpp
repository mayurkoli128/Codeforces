#include <bits/stdc++.h>
using namespace std;

// Top Down
int solve(int n) {
    int arr[n + 1] = {1, 1, 2};

    for(int i = 3; i <= n; ++i) {
        int sum = 0;
        for(int j = 0; j < i; ++j) {
            sum += arr[j]*arr[i - j - 1];
        }
        arr[i] = sum;
    }
    return arr[n];
}
int main() {
    cout << solve(4) << " ";
    cout << solve(5) << " ";
    cout << solve(6) << " ";
    cout << solve(3) << " ";

    return 0;
}