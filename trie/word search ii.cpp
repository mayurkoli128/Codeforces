#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> nums;
typedef vector<vector<char>> vec;

class trie_node {
public :
    bool flag;
    trie_node* child[26];
    
public :
    trie_node() {
        flag = false;
        memset(child, 0, sizeof(child));
    }
};

class Trie {
private:
    trie_node* trie;
public:
    Trie() {
        trie = new trie_node();   
    }
    trie_node* get_root () {
        return trie;
    }
    void insert(string word) {
        trie_node* temp = this->trie;
        

        for(int i = 0; i < word.size(); i++) {
            if(!temp->child[word[i] - 'a']) {
                temp->child[word[i] - 'a'] = new trie_node();
            }
            temp = temp->child[word[i] - 'a'];
        }
        temp->flag = true;
    }
    bool search(string word) {
        trie_node* temp = trie;
        
        for(int i = 0; i < word.size(); ++i) {
            if(temp->child[word[i] - 'a'] == nullptr)    return false;
            temp = temp->child[word[i] - 'a'];
        } 
        bool r = temp->flag;
        temp->flag = false;
        return r;
    }
};
class Solution {
Trie tree;
vector<string> res;
public:
    void solve (vector<vector<char>>& b, string w, int m, int n, trie_node* temp) {
        if (temp->flag) {
            res.push_back (w);
            temp->flag=false;
        }
        if (m >= 0 && n>=0 && m<b.size() && n < b[0].size()&&b[m][n] != '\0' && temp->child[b[m][n]-'a']) {
            char ch = b[m][n];
            b[m][n]='\0';
            solve(b, w+ch, m+1, n, temp->child[ch-'a']);
            solve(b, w+ch, m, n+1, temp->child[ch-'a']);
            solve(b, w+ch, m-1, n, temp->child[ch-'a']);
            solve(b, w+ch, m, n-1, temp->child[ch-'a']);
            b[m][n]=ch;
        }
    }
    vector<string> findWords(vector<vector<char>>& b, vector<string>& w) {
        for (int i=0; i<w.size(); ++i) {
            tree.insert(w[i]);
        }
        for (int i=0; i<b.size(); ++i) {
            for(int j=0; j<b[0].size(); ++j) {
                solve (b, "", i, j, tree.get_root());
            }
        }
        return res;
    }
};
int main () {
    vector<vector<char>> b={{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> w = {"oath","pea","eat","rain"};
    Solution s;
    auto res = s.findWords (b, w);
    for (auto s : res) {
        cout << s << " ";
    }
    return 0;
}