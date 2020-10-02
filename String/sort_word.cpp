//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
// typedef int ll;
// typedef vector<ll> nums;
// typedef vector<vector<ll>> vec;
// ll n1, n2;
// ll MOD = 1e9 + 7;

// sort by frequency


class Solution {
public:
    template <class itr, class Comp>
    itr partition (itr first, itr last, Comp cmp) {
        itr pivot=last-1;
        itr ptr1, ptr2;
        ptr1=ptr2=first;
        // 5, 1, 7, 8, 2, 3, 2
        while (ptr2 != last) {
            if (cmp (*ptr2, *pivot)) {
                swap (*ptr2, *ptr1);
                ptr1++;
            } 
            ptr2++;
        }
        swap (*ptr1, *pivot);
        return ptr1;
    }
    template <class itr, class Comp>
    void my_sort (itr first, itr last, Comp c) {
        if (first==last) {
            return ;
        }
        itr p_index = partition (first, last, c);
        
        my_sort (first, p_index, c);
        my_sort (p_index+1, last, c);
    }
    string frequencySort(string s) {
        int freq[128]={0};
        for (char ch:s) {
            freq[ch]++;
        }
        auto lamda = [=](char a, char b) {
            if (freq[a] > freq[b]) {
                return true ;
            } else if (freq[a] < freq[b]){
                return false;
            }
            return a < b;
        };
        my_sort <string::iterator,decltype(lamda)> (s.begin(), s.end(), lamda);
        return s;
    }
};