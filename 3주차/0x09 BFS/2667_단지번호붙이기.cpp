#include <bits/stdc++.h>
using namespace std;

int N;
char board[26][26];
int visited[26][26];
vector<int> answer;
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
	queue<pair<int, int>> q;
	
	int d_x[4] = { 1,0,0,-1 };
	int d_y[4] = { 0,1,-1,0 };
	int num = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == '1' && visited[i][j] != 1)
			{
				answer.push_back(num);
				num = 1;
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

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (visited[nx][ny] == 1 || board[nx][ny] == '0') continue;

					visited[nx][ny] = 1;
					num++;
					q.push({ nx,ny });
				}
			}
		}
	}
	answer.erase(answer.begin() + 0);
	answer.push_back(num);
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (auto i : answer)
		cout << i << "\n";
}