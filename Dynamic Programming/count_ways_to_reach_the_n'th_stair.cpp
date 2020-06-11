// steps you can take 1 or 2...

// Bottom-up
#include <bits/stdc++.h>
using namespace std;

int solve(int N, vector<int>& vec) {

    if(N == 0)  return 1;
    if(N < 0)   return 0;
    if(vec[N])  return vec[N];

    vec[N] = solve(N - 1,  vec) + solve(N - 2, vec);
    return vec[N];
}
// Top-Down

int solve(int N) {
    if(N == 1 || N == 2)    return N;

    int arr[N + 1] = {0, 1, 2};

    for(int i = 3; i <= N; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[N];
}
int main() {
    int N;
    cin >> N;
    vector<int> vec(N + 1);
    cout << solve(N, vec) << " ";
    cout << solve(N);

    return 0;
}