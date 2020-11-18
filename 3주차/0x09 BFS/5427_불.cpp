#include <bits/stdc++.h>
using namespace std;

int T, w, h;
char build[1001][1001];
int fire[1001][1001];
int s[1001][1001];
int visited[1001][1001];
int main()
{
	ios::sync_with_stdio(0);	cin.tie(0); 
	cin >> T;
	while (T--)
	{
		queue<pair<int, int>> q_fire;
		queue<pair<int, int>> q_s;
		
		cin >> h >> w;
		for (int i = 0; i < w; i++)
		{
			fill(visited[i], visited[i] + h, 0);
			fill(s[i], s[i] + h, -1);
			fill(fire[i], fire[i] + h, -1);
		}
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				cin >> build[i][j];
				if (build[i][j] == '@')
				{
					s[i][j] = 0;
					q_s.push({ i, j });
					visited[i][j] = 1;
				}
				
				else if (build[i][j] == '*')
				{
					fire[i][j] = 0;
					q_fire.push({ i, j });
					visited[i][j] = 1;
				}
			}
		}
		int dx[4] = { 1,-1,0,0 };
		int dy[4] = { 0,0,-1,1 };
		while (!q_fire.empty())
		{
			pair<int, int> cur = q_fire.front(); q_fire.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				//if (fire[nx][ny] != -1 && fire[nx][ny] > fire[cur.first][cur.second] + 1) 
				//	fire[nx][ny] = fire[cur.first][cur.second];
				if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
				if (visited[nx][ny] == 1 || build[nx][ny] == '#') continue;

				visited[nx][ny] = 1;
				fire[nx][ny] = fire[cur.first][cur.second] + 1;
				q_fire.push({ nx, ny });
			}
		}
		//for (int i = 0; i < w; i++)
		//{
		//	for (int j = 0; j < h; j++)
		//	{
		//		cout << fire[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		for (int i = 0; i < w; i++) fill(visited[i], visited[i] + h, 0);
		while (!q_s.empty())
		{
			pair<int, int> cur = q_s.front(); q_s.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
				if (visited[nx][ny] == 1 || build[nx][ny] != '.') continue;
				else if (fire[nx][ny] != -1 && fire[nx][ny] <= s[cur.first][cur.second] + 1) continue;

				visited[nx][ny] = 1;
				s[nx][ny] = s[cur.first][cur.second] + 1;
				q_s.push({ nx,ny });
			}
		}
		//for (int i = 0; i < w; i++)
		//{
		//	for (int j = 0; j < h; j++)
		//	{
		//		cout << s[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		int min = 10000000;
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				if (s[i][j] != -1)
				{
					if (i == 0 || i == w - 1)
					{
						min = min < s[i][j] ? min : s[i][j];
					}
					else if (j == 0 || j == h - 1)	min = min < s[i][j] ? min : s[i][j];
				}

			}
		}
		if (min == 10000000) cout << "IMPOSSIBLE\n";
		else cout << min + 1<<endl;
	}
}