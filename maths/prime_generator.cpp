#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve_sieve(vector<bool>& seive, int size) {
	int itr = sqrt(size);
	seive[0] = seive[1] = false;

	for(int i = 2; i <= itr; ++i) {
		if(seive[i] && i * i < size) {
			for(int j = i; j*i <= size; ++j) {
				seive[j*i] = false;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// cout.tie(NULL);

	int T;
	cin >> T;

	while(T--) {
		int m, n;
		cin >> m >> n;
		int size = sqrt(n) + 1;
		vector<bool> primes(n - m + 1, true);
		if(m == 1) {
			primes[0] = false;
		}
		
		vector<bool> seive(size, true);
		solve_sieve(seive, size);

		//solve(m, n, seive, primes);

		for(int i = 2; i < size; i += 1) {
			if(seive[i]) {
				int target =(m / i) * i;

				if(m > target) {
					target += i;
				}
				// attack
				for(int j = target; j <= n; j += i) {
				    if(j != i)
					    primes[j - m] = false;
				}
			}	
		}
		for(int i = 0; i < n - m + 1; ++i) {
			if(primes[i]) {
				cout << i + m << "\n";
			}
		}
		cout << "\n";
	}
}