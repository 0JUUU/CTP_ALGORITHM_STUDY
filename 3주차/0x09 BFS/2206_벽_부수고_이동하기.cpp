#include <bits/stdc++.h>
using namespace std;

int N, M;
int br;
char board[1001][1001];
int visited[1001][1001];
bool tf = false;
int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> M;
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	q.push({ 0,0 });
	visited[0][0] = 1;

	int dx[4] = { 1,0,0,-1 };
	int dy[4] = { 0,1,-1,0 };

	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (br == 0 && dir == 3) br = 1;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (br == 0)
			{
				board[nx][ny] = '0';
			}

			if (visited[nx][ny] != 0) continue;

			if (br == 1 && board[nx][ny] == '1') continue;

			visited[nx][ny] = visited[cur.first][cur.second] + 1;
			q.push({ nx,ny });

			if (nx == N - 1 && ny == M - 1) tf = true;
		}
	}
	if (tf == true) cout << visited[N - 1][M - 1];
	else cout << -1;
}