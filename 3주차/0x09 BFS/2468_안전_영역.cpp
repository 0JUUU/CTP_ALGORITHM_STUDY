#include <bits/stdc++.h>
using namespace std;

int N;
int board[101][101];
int visited[101][101];
int mx = 1, safe, h = 1;
int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
	int dx[4] = { 1,0,0,-1 };
	int dy[4] = { 0,1,-1,0 };
	queue<pair<int, int>> q;
	while (h != 101)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] > h && visited[i][j] == 0)
				{
					q.push({ i,j });
					visited[i][j] = 1;
					safe++;
				}

				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

						if (visited[nx][ny] == 1 || board[nx][ny] <= h) continue;
						visited[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}
		//cout << "mx : " << mx << " safe:" << safe << endl;
		mx = mx > safe ? mx : safe;
		safe = 0;
		for (int i = 0; i < N; i++) fill(visited[i], visited[i] + N, 0);
		h++;
	}
	cout << mx;


}