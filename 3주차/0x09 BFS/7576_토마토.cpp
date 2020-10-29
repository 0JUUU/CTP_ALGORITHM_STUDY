#include <bits/stdc++.h>
using namespace std;

int dist[1001][1001];
int board[1001][1001];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int M, N;
	cin >> M >> N;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) fill(dist[i], dist[i] + M, -1);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				dist[i][j] = 0;
				q.push({ i,j });
			}
		}
			
	}

	int d_x[4] = { 1,0,0,-1 };
	int d_y[4] = { 0,1,-1,0 };


	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + d_x[dir];
			int ny = cur.second + d_y[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (dist[nx][ny] >= 0 || board[nx][ny] == -1 || board[nx][ny] == 1) continue;

			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}


	int mx = 0;
	for (int i = 0; i < N; i++)
	{
		if (mx == -1) break;
		for (int j = 0; j < M; j++)
		{
			if (mx < dist[i][j]) mx = dist[i][j];
			if (board[i][j] == 0 && dist[i][j] == -1)
			{
				mx = -1;
				break;
			}

		}
	}
	cout << mx;
}