#include <bits/stdc++.h>
using namespace std;

int R, C;
char board[1001][1001];
int fire[1001][1001];
int jihoon[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> q_fire;
queue<pair<int, int>> q_j;
int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < R; i++)
	{
		fill(fire[i], fire[i] + C, -1);
		fill(jihoon[i], jihoon[i] + C, -1);
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (board[i][j] == 'F' && fire[i][j] == -1)
			{
				fire[i][j] = 1;
				q_fire.push({ i, j });
			}
			else if (board[i][j] == 'J')
			{
				jihoon[i][j] = 1;
				visited[i][j] = 1;
				q_j.push({ i, j });
			}
		}
	}
	int d_x[4] = { 1,0,0,-1 };
	int d_y[4] = { 0,1,-1,0 };
	while (!q_fire.empty())
	{
		pair<int, int> cur = q_fire.front(); q_fire.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + d_x[dir];
			int ny = cur.second + d_y[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (fire[nx][ny] != -1 || board[nx][ny] == '#') continue;

			fire[nx][ny] = fire[cur.first][cur.second] + 1;
			q_fire.push({ nx,ny });
		}
	}

	while (!q_j.empty())
	{
		pair<int, int> cur = q_j.front(); q_j.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + d_x[dir];
			int ny = cur.second + d_y[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (visited[nx][ny] == 1 || board[nx][ny] != '.') continue;
			else if (fire[nx][ny] != -1 && fire[nx][ny] <= jihoon[cur.first][cur.second]+1)
			{
				continue;
			}

			jihoon[nx][ny] = jihoon[cur.first][cur.second] + 1;
			visited[nx][ny] = 1;
			q_j.push({ nx,ny });
		}
	}

	int min = 10000000;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (jihoon[i][j] != -1)
			{
				if (i == 0 || i == R - 1)
				{
					min = min < jihoon[i][j] ? min : jihoon[i][j];
				}
				else if(j == 0 || j == C-1)	min = min < jihoon[i][j] ? min : jihoon[i][j];
			}

		}
	}
	if (min == 10000000) cout << "IMPOSSIBLE";
	else cout << min;
}