#include <bits/stdc++.h>
using namespace std;

int M, N, K;
int board[101][101];
int visited[101][101];
vector<int> answer;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	// M : 세로 길이, N : 가로 길이 
	cin >> M >> N >> K;
	queue<pair<int, int>> q;
	// 직사각형 칠하기
	for (int i = 0; i < K; i++)
	{
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		for (int x = lx; x < rx; x++)
		{
			for (int y = ly; y < ry; y++)
			{
				board[y][x] = 1;
			}
		}
	}

	//for (int i = 0; i < M; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << board[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	int count = 1;
	int d_x[4] = { 1,0,0,-1 };
	int d_y[4] = { 0,1,-1,0 };

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 0 && visited[i][j] != 1)
			{
				answer.push_back(count);
				count = 1;
				visited[i][j] = 1;
				q.push({ i,j });
			}
			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + d_x[dir];
					int ny = cur.second + d_y[dir];

					if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
					if (visited[nx][ny] == 1 || board[nx][ny] == 1) continue;

					count++;
					visited[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	answer.push_back(count);
	answer.erase(answer.begin() + 0);
	sort(answer.begin(), answer.end());

	cout << answer.size() << "\n";
	for (auto i : answer)
		cout << i << " ";
}