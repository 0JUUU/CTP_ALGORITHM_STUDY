#include <bits/stdc++.h>
using namespace std;


int board[101][101];
int dist[101][101];
int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = s[j] - '0';
		}
	}

	// dist를 -1로 모두 초기화 : 중요!!!!!!!
	for (int i = 0; i < N; i++) fill(dist[i], dist[i] + M, -1);
	queue<pair<int, int>> q;

	int d_x[4] = { 1,0,0,-1 };
	int d_y[4] = { 0,1,-1,0 };
	q.push({ 0, 0 });
	dist[0][0] = 1;
	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		int count = 0;
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + d_x[dir];
			int ny = cur.second + d_y[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (dist[nx][ny] >= 0 || board[nx][ny] != 1) continue;

			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx,ny });
 		}

	}
	cout << dist[N-1][M-1];
}