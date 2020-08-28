// #include <memory.h>
#include <bits/stdc++.h>
#define all(c) (c).begin(), (c).end()
using namespace std;
typedef long long ll;
typedef unordered_map<ll, ll> umap;
typedef vector<ll> vec;

void solve (string str, bool* space, string current) {

    if (current.size() == str.size()) {
        cout << current << "\n";
        //ABC
        return ;
    }
    for (int i = 0; i < (int)str.size(); ++i) {
        if (space[str[i] - 'A']) {
            space[str[i] - 'A'] = false;
            solve (str, space, current + str[i]);
            space[str[i] - 'A'] = true;
        }
    }
}
int main (){
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string str = "ABCD";
    bool space[26] = {false};

    for (int i = 0; i < str.size(); ++i) {
        space[str[i] - 'A'] = true;
    }
    string current = "";
    solve (str, space, current);
    return 0;
}
