/*
Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int N, int X, int Y, int Z, int tempN) {
    if(N == 0)  return 0;

    if(N < 0)   return tempN;

    return 1 + max(solve(N - X, X, Y, Z, tempN) + solve(N - Y, X, Y, Z, tempN) + solve(N - Z, X, Y, Z, tempN), tempN);
}
int main() {
    int N;
    int X, Y, Z;
    cin >> N;
    cin >> X >> Y >> Z;

    cout << solve(N, X, Y, Z, 0);

    return 0;
}