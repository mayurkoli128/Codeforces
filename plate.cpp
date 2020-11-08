#include <bits/stdc++.h>
#define all(nums) nums.begin(), nums.end()
using namespace std;
typedef long long int ll;
typedef vector<vector<int>>graph;
const int xx[]={1, 0, 0, -1};
const int yy[]={0,-1, 1 , 0};
int x[]={1,0,-1,-1,0,1};
int y[]={1,1,0,-1,-1,0};
const char where[]={'D', 'L', 'R', 'U'};
const int mx = 2*10e5 + 10;
const int imax = INT32_MAX;
const int imin = INT32_MIN;
template<class T>T mx(T begin, T end){return max_element(begin, end);}
template<class T>T mn(T begin, T end){return min_element(begin, end);}
template<class T>void print(vector<T>nums){for(T i:nums)cout<<i<<" ";cout<<"\n";}
template<class T>void read(vector<T>nums){for(T& i:nums)cin>>i;}
template<class T>void alloc(vector<vector<T>*>nums, T n){for(auto v:nums)v->resize(n+1);}
vector<string>s;
vector<vector<int>>d;
int m,n,k;
string ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>nums(n);
    }
    return 0;
}
graph g;
vector<int>depth, parents;
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while (t--) {
        ................................................................
        // finding prime number ....
        unordered_map<int, bool>umap;
        for (int i=2; i<=1e6; ++i) {
            bool flag=true ;
            for (int j=2; j*j<=i; ++j) {
                if (i%j==0) {
                    flag=false;
                    break;
                }
            }
            if (flag)   umap[i]=true ;
        }
        ................................................................
        // finding prefix-suffix of nums
        vector<int>nums(n), pref(n+1), suff(n+1);
        for (int i=0; i<n; ++i) cin>>nums[i], pref[i+1]=nums[i], suff[i+1]=nums[i];
        for (int i=1; i<=n; ++i) {
            pref[i] += pref[i-1];
        }
        for (int i=n-1; i>0; --i) {
            suff[i] += suff[i+1];
        }
        ................................................................
        // reading line 
        string readline() {
            string s;
            char ch;
            do {
                ch=getchar();
                s+=ch;    
            } while (ch!='\n'&&ch!=EOF);
            return s;
        }
        ................................................................
        // sqrt decomposition generelization....
        int ans = 0;
        
        for (int i=l; i<=r; ) {
            if (i%len==0 && i+len-1<=r) {
                ans += look[i/len];
                i += len;
            } else {
                ans += nums[i];
                i++;
            }
        }
        ............................................................................
        // generate all number's that consist of a1, a2, a3....
        // iterative 
            vector<int>ans={4,7};
            for (int i=0; i<=n; ++i) {
                for (int j=0; j<2; ++j) {
                    ans.push_back(ans[i]*10+ans[j]);
                }
            }
            .......................................................................
            // recursive
            void rec(string cur){
            if(cur.size() == size){
                cout << cur << '\n';
                return;
            }
            rec(cur + "4");
            rec(cur + "7");
            }
            
            int main(){
                while(++size <= 10){
                    rec("");
                }
            }
            .....................................................................
            // reading graph.....
            int n;
            cin>>n;
            g.resize(n+1), coins.resize(n+1), parent.resize(n+1);
            for (int i=0; i<n-1; ++i) {
                int u, v;
                cin>>u>>v;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            ......................................................................
            // grid generalization...
            bool isValid(int x, int y, vector<vector<bool>>& vis) {
                return x>=0&&x<m&&y>=0&&y<n&&!vis[x][y];
            }
            void dfs(int x, int y, vector<vector<bool>>& vis) {
                vis[x][y]=true ;
                
                if (a[x] == '>') {
                    // to right
                    if (isValid(x, y+1, vis)) 
                        dfs(x, y+1, vis);
                } else {
                    // to left
                    if (isValid(x, y-1, vis)) 
                        dfs(x, y-1, vis); 
                }
                if (b[y] == 'v') {
                    // to down
                    if (isValid(x+1, y, vis)) 
                        dfs(x+1, y, vis);
                } else {
                    // to up
                    if (isValid(x-1, y, vis)) 
                        dfs(x-1, y, vis);
                }
            }
    }
    return 0;
}