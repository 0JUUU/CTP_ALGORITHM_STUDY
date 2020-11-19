#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[301][301];
int tmp[301][301];
int visited[301][301];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
int cnt = 0, ans = 0, year = 0;
int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			tmp[i][j] = board[i][j];
		}
	}

	queue<pair<int, int>> q;

	// √≥¿Ω∫Œ≈Õ µŒ µ¢æÓ∏Æ ¿ÃªÛ
	for (int i = 1; i < N-1; i++)
	{
		for (int j = 1; j < M-1; j++)
		{
			if (board[i][j] != 0 && visited[i][j] == 0)
			{
				cnt++;
				visited[i][j] = 1;
				q.push({ i, j });
			}

			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();

				for (int dir = 0;dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

					if (visited[nx][ny] == 1 || board[nx][ny] == 0) continue;
					visited[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	if (cnt > 1) cout << year;
	else 
	{
		cnt = 0;
		while(cnt <= 1)
		{
			year++;
			cnt = 0;
			ans = 0;
			// ∫˘«œ ≥Ï±‚
			for (int i = 1; i < N-1; i++)
			{
				for (int j = 1; j < M-1; j++)
				{
					if (board[i][j] != 0)
					{
						int num = 0;
						for (int dir = 0; dir < 4; dir++)
						{
							int nx = i + dx[dir];
							int ny = j + dy[dir];

							if (board[nx][ny] == 0) num++;
						}
						tmp[i][j] = board[i][j] - num > 0 ? board[i][j] - num : 0;
					}
				}
			}
			for (int i = 1; i < N-1; i++)
			{
				for (int j = 1; j < M-1; j++)
				{
					board[i][j] = tmp[i][j];
				}
			}
			//for (int i = 0; i < N; i++)
			//{
			//	for (int j = 0; j < M; j++)
			//	{
			//		cout << board[i][j] << " ";
			//	}
			//	cout << endl;
			//}
			for (int i = 0; i < N; i++)
			{
				fill(visited[i], visited[i] + M, 0);
			}
			for (int i = 1; i < N-1; i++)
			{
				for (int j = 1; j < M-1; j++)
				{
					if (board[i][j] != 0 && visited[i][j] == 0)
					{
						q.push({ i, j });
						visited[i][j] = 1;
						cnt++;
					}

					while (!q.empty())
					{
						pair<int, int> cur = q.front(); q.pop();

						for (int dir = 0; dir < 4; dir++)
						{
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];

							if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

							if (visited[nx][ny] == 1 || board[nx][ny] == 0) continue;
							visited[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
			}

			for (int i = 1; i < N-1; i++)
			{
				for (int j = 1; j < M-1; j++)
				{
					if (board[i][j] != 0) ans = 1;
				}
			}
			if (ans == 0) break;
			//cout << "cnt : " << cnt << endl;
		}
		if (cnt > 1) cout << year;
		else cout << 0;
	}

}