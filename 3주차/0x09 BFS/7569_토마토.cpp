#include <bits/stdc++.h>
using namespace std;

int M, N, K;
int tomato[101][101][101];
int visited[101][101][101];

int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> M >> N >> K;
	queue<pair<int, pair<int, int>>> q;

	// i = z, j = x, k = y
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> tomato[i][j][k];
			}
		}
	}

	
	int d_x[6] = { 0,0,1,0,0,-1 };
	int d_y[6] = { 0,0,0,1,-1,0 };
	int d_z[6] = { 1,-1,0,0,0,0 };


	// i = z, j = x, k = y
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (tomato[i][j][k] == 1 && visited[i][j][k] != 1)
				{
					q.push({ i, {j, k} });
					visited[i][j][k] = 1;
				}
			}
		}
	}


	// i = z, j = x, k = y
	while (!q.empty())
	{
		pair<int, pair<int, int>> cur = q.front(); q.pop();

		for (int dir = 0; dir < 6; dir++)
		{
			int nx = cur.second.first + d_x[dir];
			int ny = cur.second.second + d_y[dir];
			int nz = cur.first + d_z[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= K) continue;

			if (visited[nz][nx][ny] == 1 || tomato[nz][nx][ny] != 0) continue;

			tomato[nz][nx][ny] = tomato[cur.first][cur.second.first][cur.second.second] + 1;
			visited[nz][nx][ny] = 1;
			q.push({ nz,{nx,ny} });
		}
	}
	//for (int i = 0; i < K; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		for (int k = 0; k < M; k++)
	//		{
	//			cout << tomato[i][j][k] << " ";
	//		}
	//		cout << endl;
	//	}
	//}
	
	int max = -1;
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (tomato[i][j][k] == 0)
				{
				
					max = 0;
					break;
				}
				max = max < tomato[i][j][k] ? tomato[i][j][k] : max;
			}
			if (max == 0) break;
		}
		if (max == 0) break;
	}

	if (max == 0) cout << "-1";
	else if (max == 1) cout << "0";
	else cout << max - 1;
}