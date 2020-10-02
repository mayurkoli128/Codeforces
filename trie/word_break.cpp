#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll> nums;
typedef vector<vector<char>> vec;
int n1, n2;
int MOD = 1e9 + 7;
vector<int> nums1, nums2;
struct trie_node
{
    bool flag;
    trie_node *child[26];

    trie_node()
    {
        flag = false;
        memset(child, 0, sizeof(child));
    }
};
class trie
{
    trie_node *root;

public:
    trie()
    {
        root = new trie_node();
    }
    void insert(string str)
    {
        trie_node *temp = root;

        for (char ch : str)
        {
            if (temp->child[ch - 'a'] == nullptr)
            {
                temp->child[ch - 'a'] = new trie_node();
            }
            temp = temp->child[ch - 'a'];
        }
        temp->flag = true;
    }
    trie_node *get_root()
    {
        return root;
    }
};
class Solution
{
    trie dict;

public:
    bool wordBreak(string s, vector<string> &words)
    {
        trie_node *temp = dict.get_root(), *cur;

        for (string word : words)
        {
            dict.insert(word);
        }
        int len = s.size();
        vector<bool> f (len+1);
        f[len]=true;
        
        for (int i = len - 1; i >= 0; i--) {
            cur = temp;
            for (int j = i; cur != nullptr && j < len ; j++) {
                cur = cur->child[s[j]-'a'];
                if (cur != nullptr && cur->flag && f[j + 1]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[0];
    }
};
int main () {
    string s = "leetcode";
    vector<string>wordDict = {"leet", "code"};
    Solution st;
    st.wordBreak(s, wordDict);
    return 0;
}