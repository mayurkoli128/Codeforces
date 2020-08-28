#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vec (5, vector<int>(5, 0));
vector<vector<int>> d(2, vector<int>(4, 0));
int r, c;

bool isValid(vector<int>& d) {
    if(d[0] < r && d[0] >= 0 && d[1] < c && d[1] >= 0 && vec[d[0]][d[1]]) {
        return true ;
    } 
    return false ;
}
void solve(int m, int n) {
    
    for (int i = 0; i < 4; ++i) {
        vector<int> c = {d[i][0] + m, d[i][1] + n};

        if(isValid(c)) {
            vec[c[0]][c[1]] = 0;
            solve(c[0], c[1]);
        }
    }
}
int main() {
    d = {{-1,0}, {0,-1}, {0,1}, {1,0}};
    vec = {{1,1,1,1,0}, {1,1,0,1,0}, {0,1,0,0,1}, {0,0,0,1,1}, {1,0,1,0,0}};

    r = vec.size();
    
    if(r == 0)  return 0;

    c = vec[0].size();
    int cnt = 0;
    for (int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if (vec[i][j]) {
                vec[i][j] = 0;
                solve (i, j);
                cnt += 1;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}