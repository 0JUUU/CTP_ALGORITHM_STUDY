#include <bits/stdc++.h>
using namespace std;

int L, R, C;
int LX, LY, LZ;
char building[32][32][32];
int visited[32][32][32];
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	while (1)
	{
		string number;
		int x = 0;
		queue<pair<pair<int, int>, int>> q;
		getline(cin, number);
		stringstream ss(number);
		string k;
		ss >> k; L = stoi(k);
		ss >> k; R = stoi(k);
		ss >> k; C = stoi(k);
		
		if (L == 0 && R == 0 && C == 0) break;
		for (int l = 0; l < L;l++)
		{
			for (int r = 0; r <= R; r++)
			{
				string s;
				getline(cin, s);
				if (s != "")
				{
					for (int c = 0; c < C; c++)
					{
						building[r][c][l] = s[c];
						if (s[c] == 'S')
						{
							visited[r][c][l] = 1;
							q.push({ {r,c},l });
						}
						if (s[c] == 'E')
						{
							LX = r; LY = c; LZ = l;
						}
					}
				}
			}
		}
		while (!q.empty())
		{
			pair<pair<int, int>, int> cur = q.front(); q.pop();
			for (int dir = 0; dir < 6; dir++)
			{
				int nx = cur.first.first + dx[dir];
				int ny = cur.first.second + dy[dir];
				int nz = cur.second + dz[dir];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= L) continue;
				if (visited[nx][ny][nz] != 0 || building[nx][ny][nz] == '#') continue;
				visited[nx][ny][nz] = visited[cur.first.first][cur.first.second][cur.second] + 1;
				q.push({ {nx,ny},nz });
				if (nx == LX && ny == LY && nz == LZ) break;
			}
		}
		if (visited[LX][LY][LZ] == 0) cout << "Trapped!\n";
		else
			cout <<"Escaped in "<< visited[LX][LY][LZ] - 1 << " minute(s).\n";
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				for (int k = 0; k < L; k++)
				{
					visited[i][j][k] = 0;
				}
			}
		}
		while (!q.empty()) q.pop();
 		//for (int l = 0; l < L; l++)
		//{
		//	for (int r = 0; r < R; r++)
		//	{
		//		for (int c = 0; c < C; c++)
		//			cout << building[r][c][l] ;
		//		cout << endl;
		//	}
		//}

	}
}