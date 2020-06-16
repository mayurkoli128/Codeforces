// Count of substrings of length K with exactly K distinct characters.

#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public :
    int distinct_characters(string str, int k) {   
        unordered_map<char, int> map;
        int start = 0;
        int size = str.size(), cnt = 0;

        for(int i = 0; i < size; ++i) {
            map[str[i]]++;

            if(i + 1 >= k) {
                if(map.size() == k) {
                    cnt++;
                }
                if(--map[str[start]] == 0) map.erase(str[start]);
                start++;
            }
        }
    return cnt;
    }
};
int main() {
    string s = "aabcdabbcdc";
    Solution x;
    std :: cout << x.distinct_characters(s, 3);
    return 0;
}