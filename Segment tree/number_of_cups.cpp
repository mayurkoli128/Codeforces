#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {1,3,4,2,2};

    int fast = vec[0];
    int slow = vec[0];

    do {
        slow = vec[slow];
        fast = vec[vec[fast]];
    } while(slow != fast);
    
    slow = vec[0];

    while(slow != fast) {
        slow = vec[slow];
        fast = vec[fast];
    }
    
    cout << vec[slow] << " ";

    return 0;
}