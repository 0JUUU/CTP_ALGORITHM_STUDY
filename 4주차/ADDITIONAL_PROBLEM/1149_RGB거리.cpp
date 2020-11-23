#include <bits/stdc++.h>
using namespace std;

int N, house[1002][3], dp[1002][3];
int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> house[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 0) dp[i][j] = house[i][j];
			else
			{
				int tmp = 10000000;
				for (int k = 0; k < 3; k++)
				{
					if (j != k)
					{
						tmp = min(tmp, dp[i - 1][k]);
					}
				}
				dp[i][j] = house[i][j] + tmp;
			}
		}
	}
	int answer = 10000000;
	for (int i = 0; i < 3; i++) answer = min(answer, dp[N - 1][i]);
	cout << answer;
}