#include <bits/stdc++.h>
using namespace std;

int N;
char board[101][101];
int visited[101][101];
int R, G, B, RG;
int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	queue<pair<int, int>> q_R;
	queue<pair<int, int>> q_G;
	queue<pair<int, int>> q_B;
	queue<pair<int, int>> q_RG;

	int d_x[4] = { 1,0,0,-1 };
	int d_y[4] = { 0,1,-1,0 };

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 0)
			{
				visited[i][j] = 1;
				switch (board[i][j])
				{
				case 'R':
					q_R.push({ i,j });
					R++;
					break;
				case 'G':
					q_G.push({ i,j });
					G++;
					break;
				case 'B':
					q_B.push({ i,j });
					B++;
					break;
				}
			}

			while (!q_R.empty())
			{
				pair<int, int> cur = q_R.front(); q_R.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + d_x[dir];
					int ny = cur.second + d_y[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (visited[nx][ny] == 1 || board[nx][ny] != 'R') continue;

					visited[nx][ny] = 1;
					q_R.push({ nx,ny });
				}
			}

			while (!q_G.empty())
			{
				pair<int, int> cur = q_G.front(); q_G.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + d_x[dir];
					int ny = cur.second + d_y[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (visited[nx][ny] == 1 || board[nx][ny] != 'G') continue;

					visited[nx][ny] = 1;
					q_G.push({ nx,ny });
				}
			}

			while (!q_B.empty())
			{
				pair<int, int> cur = q_B.front(); q_B.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + d_x[dir];
					int ny = cur.second + d_y[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (visited[nx][ny] == 1 || board[nx][ny] != 'B') continue;

					visited[nx][ny] = 1;
					q_B.push({ nx,ny });
				}
			}
		}
	}
	for (int i = 0; i < N; i++) fill(visited[i], visited[i] + N, 0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 0)
			{
				visited[i][j] = 1;
				switch (board[i][j])
				{
				case 'R':
					q_RG.push({ i,j });
					RG++;
					break;
				case 'G':
					q_RG.push({ i,j });
					RG++;
					break;
				default:
					break;
				}
			}

			while (!q_RG.empty())
			{
				pair<int, int> cur = q_RG.front(); q_RG.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + d_x[dir];
					int ny = cur.second + d_y[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (visited[nx][ny] == 1 || board[nx][ny] == 'B') continue;

					visited[nx][ny] = 1;
					q_RG.push({ nx,ny });
				}
			}

		}
	}

	cout << R + G + B << " "<<RG+B;
	
}