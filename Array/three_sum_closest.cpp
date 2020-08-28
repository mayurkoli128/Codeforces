#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>& nums, int target) {
    int ans = 0;
    int distance = INT32_MAX;
    int size = nums.size();

    sort(nums.begin(), nums.end());

    for(int i = 0; i < size; ++i) {
        int p1 = i + 1;
        int p2 = size - 1;

        while(p1 < p2) {
            int sum = nums[p1] + nums[p2] + nums[i]; 

            if(sum == target) {
                return target;
            } 
            else if(sum > target) {
                p2--;
            } else {
                p1++;
            }
            if(distance > abs(target - sum)) {
                distance = abs(target - sum);
                ans = sum;
            }
        }
    }
    return ans;
}
int main() {
    vector<int> vec = {-1,2,1,-4};
    int target = 1;

//     [1,1,-1,-1,3]
// 1

    cout << solve(vec, target);

    return 0;
}