#include <iostream>
#include <vector>
using namespace std;


void solve(vector<int>& vec, int size) {

    int left = 0, right = size - 1, mid = 0;

    while (mid < right && mid < size) {
        switch(vec[mid]) {
            case 0: 
                if(vec[left] == 0) {
                    left++;
                } else if(mid > left) {
                    swap(vec[left++], vec[mid++]);
                } else {
                    mid++;
                }
            break;

            case 1:
                mid++;
            break;

            case 2:
                if(vec[right]== 2) {
                    right--;
                } else {
                    swap(vec[right], vec[mid]);
                }
            break;
        }
    }

}

int main() {
    vector<int> vec = {0,1,1,0,1,2,1,2,0,0,0,1};
    solve(vec, vec.size());

    for(int i : vec) {
        cout << i << " ";
    }
    return 0;
}