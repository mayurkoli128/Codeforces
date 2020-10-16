#include <bits/stdc++.h>
#define all(nums) nums.begin(), nums.end()
using namespace std;
typedef long long int ll;
typedef vector<vector<int>>graph;
const int xx[]={0,1,0,-1};
const int yy[]={1,0,-1,0};const int mx = 2*10e5 + 10;
const int imax = INT32_MAX;
const int imin = INT32_MIN;
graph g;
vector<int>dp;
vector<vector<char>>s;
int m,n;
 
bool isValid(int x, int y) {
    return x>=0&&x<m&&y>=0&&y<n&&s[x][y]=='.';
}
void dfs (int x, int y) {
    s[x][y]='#';
    for (int i=0; i<4; ++i) {
        int nx=xx[i]+x, ny=yy[i]+y;
        if (isValid(nx, ny)) 
            dfs(nx, ny);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    // cin>>t;
    while (t--) {
        cin>>m>>n;
        s.resize(m, vector<char>(n));
 
        for(int i=0; i<m; ++i) 
            for(int j=0; j<n; ++j) 
                cin>>s[i][j];
        int cnt=0;
        for (int i=0; i<m; ++i) 
            for (int j=0; j<n; ++j) 
                if (s[i][j] == '.') 
                    dfs (i, j), ++cnt;
        cout<<cnt;
    }
    return 0;
}