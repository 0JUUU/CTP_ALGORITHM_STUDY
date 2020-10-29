#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;
int board[501][501];
int visited[501][501];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int count = 0, mx = 0;
	int d_x[4] = { 1,0,0,-1 };
	int d_y[4] = { 0,1,-1,0 };
	queue<pair<int, int>> q;
	string s, k;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			/*
			string s;
			cin >> s;
			board[i][j] = stoi(s);
			*/

			cin >> board[i][j];
		}
	}

	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 1 && visited[i][j] != 1)
			{
				visited[i][j] = 1;
				q.push({ i,j });
				count++;
				tmp++;
			}
			while (!q.empty())
			{
				pair<int, int> p = q.front(); q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = p.X + d_x[dir];
					int ny = p.Y + d_y[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

					if (visited[nx][ny] == 1 || board[nx][ny] != 1) continue;

					visited[nx][ny] = 1;
					tmp++;
					q.push({ nx,ny });
				}
				
			}

			//if (tmp > max) max = tmp;

			// easy way
			mx = max(mx, tmp);
			tmp = 0;
		}
	}
	cout << count << '\n' << mx;
}