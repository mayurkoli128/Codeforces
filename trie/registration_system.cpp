#include <bits/stdc++.h>
using namespace std;
#define all(nums) nums.begin(), nums.end()
#define allr(nums) nums.rbegin(), nums.rend()
#define len(a) int((a).size())
typedef long long int ll;
const ll imax = INT64_MAX;
const ll imin = INT64_MIN;
typedef vector<vector<int>> graph;
graph g;
template<class T>T cal(T n) {return (n*1ll*(n+1))/2;}
template<class T>T mx(T begin, T end){return max_element(begin, end);}
template<class T>T mn(T begin, T end){return min_element(begin, end);}
template<class T>void getUnique(vector<T>& nums){sort(nums.begin(), nums.end()); nums.erase(unique(nums.begin(), nums.end()), nums.end());}
template<class T>void print(vector<T>nums){for(T i:nums)cout<<i<<" ";cout<<"\n";}
template<class T>void read(vector<T>&nums){for(T& i:nums)cin>>i;}

struct TrieNode {
    TrieNode* child[26];
    int cnt;
    TrieNode() {
        cnt = 0;
        memset(child, 0, sizeof(child));
    }
};
class Trie {
TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string s) {
        TrieNode* temp = root;
        for (int i=0; i<len(s); ++i) {
            int in = s[i]-'a';
            if (!temp->child[in]) {
                temp->child[in] = new TrieNode();
            } 
            temp = temp->child[in];
        }
        temp->cnt++;
    }
    int search(string s) {
        TrieNode* temp = root;
        for (int i=0; i<len(s); ++i) {
            int in = s[i]-'a';
            if (!temp->child[in]) {
                return 0;
            } 
            temp = temp->child[in];
        }
        return temp->cnt ;
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    // cin>>t;
    while(t--) {
        int n;
        cin>>n;
        Trie trie;
        for (int i=0; i<n; ++i) {
            string s;
            cin>>s;
            int curr_cnt = trie.search(s);
            
            if (curr_cnt > 0) {
                cout << s + to_string(curr_cnt) <<"\n";
            } else {
                cout<<"OK\n";
            }
            trie.insert(s);
        }
    }
    return 0;   
}