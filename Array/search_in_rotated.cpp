#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &vec, int l, int r, int target)
{
    if(l > r)  return -1;

    int mid = (l + r) >> 1;

    if (vec[mid] == target)
    {
        return mid;
    }

    else if (vec[l] <= vec[mid])
    {
        if (vec[l] < target && vec[mid] > target)
        {
            return solve(vec, l, mid - 1, target);
        }
        else
        {
            return solve(vec, mid + 1, r, target);
        }
    }
    int x = solve (vec, l, mid - 1, target);
    
    if(x != -1) return x;
    
    return solve(vec, mid + 1, r, target);
}

// int solve(vector<int> &vec, int target)
// {
//     int left = 0, right = vec.size() - 1;
//     int index = -1;

//     while (left <= right)
//     {
//     }
//     return index;
// }

int main()
{
    vector<int> vec = {4,5,6,7,0,1,2};
    cout << solve(vec, 0, vec.size() - 1, 0);
    return 0;
}