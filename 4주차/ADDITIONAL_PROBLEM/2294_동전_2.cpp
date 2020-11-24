#include <bits/stdc++.h>
using namespace std;

int n, k;
int coin[101];
int board[200000];
int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> n >> k;
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
		board[coin[i]] = 1;
		q.push(coin[i]);
	}
	while (!q.empty())
	{
		int nx = 0;
		int cur = q.front(); q.pop();
		if (cur >= 3 * k) break;
		for (int dir = 0; dir < n; dir++)
		{
			nx = cur + coin[dir];

			if (nx < 0 || nx >= 3*k) continue;
			if (board[nx] != 0) continue;

			board[nx] = board[cur] + 1;
			q.push(nx);
		}
	}
	if (board[k] == 0) cout << "-1\n";
	else cout << board[k] << "\n";
}