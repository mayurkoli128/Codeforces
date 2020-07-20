/* 
Count number of hops 

A frog jumps either 1, 2 or 3 steps to go to top. In how many ways can it reach the top. As the answer will be large print the answer modulo 1000000007.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains one line of input N denoting the top.

Output:
For each testcase, in a new line, print the number of ways to reach the top. Print  answer modulo 1e9+7.

Constraints:
1≤ T ≤ 100
1 ≤ N ≤ 105

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Example:
Input:
2
1
4
Output:
1
7
Explantion:
Below are the 7 ways to reach 4.
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step
*/
typedef long long int ln;

#include <bits/stdc++.h>
using namespace std;

ln solve(int N, ln cnt, vector<ln>& arr) {
    if(N == 0) {
        //success
        return 1;
    }

    if(N < 0) {
        return 0;
    }

    if(arr[N])  return arr[N];

    cnt += arr[N - 1] = solve(N - 1, cnt, arr);
    if(N >= 2)
        cnt += arr[N - 2] = solve(N - 2, cnt, arr);
    if(N >= 3)
        cnt += arr[N - 3] = solve(N - 3, cnt, arr); 

    return cnt;
}
int main() {
    int N;
    cin >> N;
   vector<ln> dp(N + 1, 0);
    
    cout << solve(N, 0, dp);

    return 0;
}