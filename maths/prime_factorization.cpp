

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    int itr = sqrt(N);
    for(int i = 2; i <= itr; ++i) {
        int cnt = 0;
        while(N % i == 0) {
            N /= i;
            cnt++;
        }
        if(cnt) {
            cout << i << " " << cnt << "\n";
        }
    }
    if(N > 1) {
        cout << N << " " << 1 << "\n";
    }
    return 0;
}