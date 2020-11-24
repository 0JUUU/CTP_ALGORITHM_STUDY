#include <bits/stdc++.h>
using namespace std;

int T, n;
int dp[12];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while (T--)
	{
		cin >> n;
		for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[n] << "\n";

	}
}