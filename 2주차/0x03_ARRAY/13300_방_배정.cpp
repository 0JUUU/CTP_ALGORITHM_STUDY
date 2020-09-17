#include <bits/stdc++.h>
using namespace std;

int student[6][2];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N, K, answer = 0;;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int S, Y;
		cin >> S >> Y;
		student[Y - 1][S]++;
	}
	
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (student[i][j] % K == 0) answer += student[i][j] / K;
			else
				answer += ((student[i][j] / K) + 1);
		}
	}
	cout << answer;
}