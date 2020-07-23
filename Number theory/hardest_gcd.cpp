#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int N, K;

		cin >> N >> K;
		bool flag = true;
		int gcd = 0;

		for (int i = 0; i < N; ++i)
		{
			int in;
			cin >> in;
			gcd = __gcd(gcd, in);
		}
		int itr = sqrt(gcd);

		for (int i = 2; i <= itr; ++i)
		{
			if (gcd % i == 0)
			{
				if (i > K)
				{
					flag = false;
					break;
				}
				while (gcd % i == 0)
				{
					gcd /= i;
				}
			}
		}
		if (gcd != 1 && gcd > K)
		{
			flag = false;
		}
		if(flag) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

}