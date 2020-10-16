#include <bits/stdc++.h>
#define all(nums) nums.begin(), nums.end()
using namespace std;
typedef long long int ll;
typedef vector<vector<int>>graph;
const int xx[]={0,1,0,-1};
const int yy[]={1,0,-1,0};
const char where[]={'L', 'U', 'R', 'D'};
const int mx = 2*10e5 + 10;
const int imax = INT32_MAX;
const int imin = INT32_MIN;
graph g;
vector<int>dp;
vector<vector<char>>mat;
vector<vector<int>>ans;
int m,n;

bool isValid(int x, int y) {
    return x>=0&&x<m&&y>=0&&y<n;
}
void solve(int x, int y) {
    queue<vector<int>>q;
    q.push({x, y, 0});
    ans[x][y]=0;
    mat[x][y]='#';
    while(!q.empty()) {
        auto ele=q.front();
        q.pop();
        for(int i=0; i<4; ++i) {
            int nx=xx[i]+ele[0], ny=yy[i]+ele[1];
            if (isValid(nx,ny) && mat[nx][ny]!='#') {
                mat[nx][ny]='#';
                q.push({nx, ny, ele[2]+1});
                ans[nx][ny]=ele[2]+1;
            }
        }
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
        mat.resize(m, vector<char>(n));
        ans.resize(m, vector<int>(n, imax));
        int x, y, p, q;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                cin>>mat[i][j];
                if (mat[i][j]=='A') 
                    x=i, y=j;
                if(mat[i][j]=='B') 
                    p=i, q=j;
            }
        }
        solve(x, y);
        for(int i=0;i<m; ++i) 
            for(int j=0; j<n; ++j)
                cout<<ans[i][j]<<" \n"[j==n-1];
        bool flag=true;
        string path="";
        while (x!=p || y!=q) {
            int d=imax;
            char w;
            ans[p][q]=imax; 
            int tp=p, tq=q;
            for(int i=0; i<4; ++i) {
                int nx=xx[i]+tp, ny=yy[i]+tq;
                if(isValid(nx, ny) && d>ans[nx][ny]) 
                    p=nx, q=ny, d=ans[nx][ny], w=where[i];
            }
            path += w;
            if(d==imax) {
                flag=false;
                break;
            }
        }
        if (!flag)   cout<<"NO";
        else {
            reverse(all(path));
            cout<<"YES\n"<<path.size()<<"\n";
            cout<<path;
        }
    }
    return 0;
}