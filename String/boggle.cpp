// boggle problem == > using suffix_tree

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
typedef vector<vector<bool>> vec;
vector<string> result;
vector<vector<char>> board;

struct trie_node
{
    bool flag;
    trie_node *child[26];
    trie_node()
    {
        flag = true;
        memset(child, 0, sizeof(child));
    }
    trie_node *get(const char &a)
    {
        return child[a - 'a'];
    }
    void set(const char &a)
    {
        child[a - 'a'] = new trie_node();
        flag = false;
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
    // insert into trie...

    void insert(string s)
    {
        int size = s.size();
        trie_node *temp = root;

        for (int i = 0; i < size; ++i)
        {
            if (temp->get(s[i]) == nullptr)
            {
                temp->set(s[i]);
            }
            temp = temp->get(s[i]);
        }
    }
    //search into trie...

    bool search(string s)
    {
        int size = s.size();
        trie_node *temp = root;

        for (int i = 0; i < size; ++i)
        {
            if (temp->get(s[i]) == nullptr)
            {
                return false;
            }
            temp = temp->get(s[i]);
        }
        return temp->flag;
    }
    // deletion from trie...(not required)
};

int r, c;
int d[][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

bool is_valid(int m, int n, vec visited)
{
    if (m >= 0 && m < r && n >= 0 && n < c && !visited[m][n])
    {
        return true;
    }
    return false;
}

void find_word(int m, int n, trie &t, string current, vec visited)
{
    if (t.search(current))
    {
        result.push_back(current);
        return;
    }

    for(int i = 0; i < 4; ++i) {
        int newR = d[i][0] + m;
        int newC = d[i][1] + n;

        if(is_valid(newR, newC, visited)) {
            visited[newR][newC] = true;
            find_word(newR, newC, t, current + board[newR][newC], visited);
            visited[newR][newC] = false;
        }
    }
       
}
string getString(char x) 
{ 
    string s(1, x); 
    return s;    
} 
int main()
{
    
    trie t;
    board =  {{'o','a','a','n'},
                {'e','t','a','e'},
                {'i','h','g','r'},
                {'i','f','l','v'}
                };

    r = board.size();
    c = board[0].size();
    vec visited(r, vector<bool>(c, 0));


    vector<string> words = {"oath","pea","eat","rain", "aaklv", "atadva", "iflvr", "aag"};

    for (int i = 0; i < words.size(); ++i)
    {
        t.insert(words[i]);
    }
    

    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            visited[i][j] = true;
            find_word(i, j, t, getString(board[i][j]), visited);
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }

    // cout << t.search("rain ") << " ";
    // cout << t.search("koli") << " ";
    // cout << t.search("oat") << " ";
    // cout << t.search("oath") << " ";
    // cout << t.search("pea") << " ";
    // cout << t.search("rain") << " ";

    cout << "\n";
    return 0;
}