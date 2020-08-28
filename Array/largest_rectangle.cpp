// time complexity analysis...
// build tree will take linear time o(N)
// after that for each query getMin function will take o(logN)
// in the worst case when array is not shuffle i.e, either array is increasing or int decreasing order N recursive call's will be create.

// Total time complexity -> O(N)+O(logN)+o(NlogN) = o(NlogN)


// #include <memory.h>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll> vec;



auto lamda = [] (pair<long,long>p1, pair<long,long> p2) {
            return p1.first < p2.first;
};
typedef vector<int> vec;
int SIZE = 1;
class Solution {
int area = 0;
vector<pair<long,long>> segment;
public:
    void build (int l, int r, int index, vec& nums) {
        if (l == r) {
            if (l < nums.size())
                segment[index]={nums[l], l};
            return;
        }
        //  if(l > ry || r < lx)    return {INT32_MAX, 0};
        int mid = (l+r) >> 1;
        build (l, mid, index*2+1, nums);
        build (mid+1, r, index*2+2, nums);

        segment[index] = min(segment[index*2+1], segment[index*2+2], lamda);
    }
    pair<long,long> getMin(int lx, int ly, int l, int r, int index, vector<int>& nums) {
        if (l > ly || r < lx) {
            return {INT64_MAX, -1};
        }
        if (l >= lx && r <= ly) {
            return segment[index];
        }
        int mid = (l+r)>>1;

        auto x=getMin (lx, ly, l, mid, index*2+1, nums);
        auto y=getMin (lx, ly, mid+1,r, index*2+2, nums);

        return min (x, y, lamda);
    }
    void solve (vector<int>& nums, int l, int r) {
        if (l == r) {
            return ; 
        }
        int index = getMin (l, r-1, 0, SIZE-1, 0, nums).second;
        area = max (area, nums[index]*(r-l));
        solve (nums, l, index);
        solve (nums, index+1, r);
    }
    int largestRectangleArea(vector<int>& nums) {
       
        while (nums.size() > SIZE) {
            SIZE *= 2;
        }
        segment.assign (SIZE*2-1, {0,0});
        build (0, SIZE-1, 0, nums);
        solve (nums, 0, nums.size());
        return area;
    }
};
