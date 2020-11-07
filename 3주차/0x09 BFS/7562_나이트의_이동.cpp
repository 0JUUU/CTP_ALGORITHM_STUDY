#include <bits/stdc++.h>
using namespace std;

int T, I;
int cur[2];
int want[2];
int visited[301][301];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	
	while (T--)
	{
		queue<pair<int, int>> q;
		cin >> I;
		cin >> cur[0] >> cur[1] >> want[0] >> want[1];
		q.push({ cur[0],cur[1] });
		visited[cur[0]][cur[1]] = 1;

		int d_x[8] = { 1,1,2,2,-1,-1,-2,-2 };
		int d_y[8] = { 2,-2,1,-1,2,-2,1,-1 };

		while (!q.empty())
		{
			pair<int, int> now = q.front();	q.pop();

			for (int dir = 0; dir < 8; dir++)
			{
				int nx = now.first + d_x[dir];
				int ny = now.second + d_y[dir];

				if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
				if (visited[nx][ny] != 0) continue;

				visited[nx][ny] = visited[now.first][now.second] + 1;

				if (nx == want[0] && ny == want[1]) break;
				q.push({ nx,ny });
			}
		}

		cout << visited[want[0]][want[1]] - 1 << "\n";
		for (int i = 0; i < I; i++) fill(visited[i], visited[i] + I, 0);
	}
}