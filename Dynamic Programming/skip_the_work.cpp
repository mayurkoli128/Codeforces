#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<int>& tasks) {
    int size = tasks.size();
    int current_cost = 0;
    int min_cost = INT32_MAX;

    int include = 0, exclude = 0;

    for(int i = 0; i < size; ++i) {
        current_cost = min(include, exclude) + tasks[i];

        exclude = include;
        include = current_cost;

        min_cost = min(exclude, include);
    }    
    return min_cost;
}

// int min_cost = INT32_MAX;

// void solve(vector<int>& tasks, int index, int size, bool flag, int cost) {
//     if(index >= size)   {
//         min_cost = min(min_cost, cost);
//         return;
//     }

//     solve(tasks, index + 1, size, true, cost + tasks[index]); 
    
//     if(flag == true) {
//         solve(tasks, index + 1, size, false, cost);
//     }
// }

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector<int> tasks(N);

        for(int i = 0; i < N; ++i) {
            int in;
            cin >> in;
            tasks[i] = in;
        }
        cout << solve(tasks) << "\n";
    }
}   
