#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solve(vector<int>& nums, int size) {
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < size - 1; ++i) {
        int target = -nums[i];
        int p1 = i + 1;
        int p2 = size - 1;

        while(p1 < p2) {
            if(nums[p1] + nums[p2] == target) {
                result.push_back({nums[p1], nums[p2], -target});
                p1++; p2--;

                while(p1 < p2 && nums[p1] == nums[p1 - 1] && nums[p2] == nums[p2 + 1]) {
                    p1++; p2--;
                }

            } else if(nums[p1] + nums[p2] > target) {
                p2--;
            } else {
                p1++;
            }
        } 
    }
    return result;
}
int main() {
    vector<int> vec = {-1, 0, 1, 2, -1, -4};

    solve(vec, vec.size());

    return 0;
}