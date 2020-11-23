#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int day[101][101];
int dp[101][101];
int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				cin >> day[i][j];
		}
		
		for (int j = 0; j < M; j++)
		{
			for (int i = 0; i < N; i++)
			{
				if (j == 0) dp[i][j] = day[i][j];
				else
				{
					int tmp = 1000000;
					for (int k = 0; k < N; k++)
					{
						if (k != i)
						{
							tmp = min(tmp, dp[k][j-1]);
						}		
					}
					dp[i][j] = day[i][j] + tmp;
				}

			}

		}
		int answer = dp[0][M - 1];
		for (int i = 1; i < N; i++)
		{
			answer = min(answer, dp[i][M - 1]);
			// answer = answer > dp[i][M - 1] ? dp[i][M - 1] : answer;
		}
		cout << answer << "\n";

		for (int i = 0; i < N; i++)
		{
			fill(day[i], day[i] + M, 0);
			fill(dp[i], dp[i] + M, 0);
		}
	}

}