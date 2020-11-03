#include <bits/stdc++.h>
using namespace std;

int T, M, N, K;
int board[51][51];
int visited[51][51];
int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++)
		{
			int a, b;
			cin >> a >> b;
			board[a][b] = 1;
		}
		queue<pair<int, int>> q;

		int d_x[4] = { 1,0,0,-1 };
		int d_y[4] = { 0,1,-1,0 };
		int count = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] == 1 && visited[i][j] != 1)
				{
					q.push({ i,j });
					visited[i][j] = 1;
					count++;
				}

				while (!q.empty())
				{
					pair<int, int> cur = q.front();		q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + d_x[dir];
						int ny = cur.second + d_y[dir];

						if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
						if (visited[nx][ny] == 1 || board[nx][ny] != 1) continue;

						visited[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}
		cout << count << "\n";
		// 여러 테스트케이스 진행을 위해 초기화
		for (int i = 0; i < M; i++)
		{
			fill(board[i], board[i] + N, 0);
			fill(visited[i], visited[i] + N, 0);
		}
	}

}