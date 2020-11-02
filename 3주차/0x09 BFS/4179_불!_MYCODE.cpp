#include <bits/stdc++.h>
using namespace std;

char board[1001][1001];
int fire[1001][1001];
int jihoon[1001][1001];
int visited[1001][1001];
int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	int R, C;
	cin >> R >> C;
	queue<pair<int, int>> q_fire;
	queue<pair<int, int>> q_jihoon;
	for (int i = 0; i < R; i++) fill(fire[i], fire[i] + C, -1);
	// 미로 입력
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
		}
	}

	int d_x[4] = { 1,0,0,-1 };
	int d_y[4] = { 0,1,-1,0 };

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			// 불 ('F') 초기 위치 찾기
			if (board[i][j] == 'F' && fire[i][j] == -1)
			{
				fire[i][j] = 1;
				q_fire.push({ i,j });
			}
			// 지훈 ('J') 초기 위치 찾기
			if (board[i][j] == 'J')
			{
				jihoon[i][j] = 1;
				visited[i][j] = 1;
				q_jihoon.push({ i,j });
			}
		}
	}
	// 불 옮겨붙는 날짜 계산

	while (!q_fire.empty())
	{
		pair<int, int> cur = q_fire.front(); q_fire.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + d_x[dir];
			int ny = cur.second + d_y[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

			if (fire[nx][ny] != -1 || board[nx][ny] != '.') continue;

			fire[nx][ny] = fire[cur.first][cur.second] + 1;
			q_fire.push({ nx,ny });
		}
	}

	/*
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << fire[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	*/

	while (!q_jihoon.empty())
	{
		pair<int, int> cur = q_jihoon.front(); q_jihoon.pop();


		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + d_x[dir];
			int ny = cur.second + d_y[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			int tmp = jihoon[nx][ny];
			jihoon[nx][ny] = jihoon[cur.first][cur.second] + 1;
	
			if (fire[nx][ny] != -1)
			{
				if ((fire[nx][ny] <= jihoon[nx][ny]) || (visited[nx][ny] == 1) || board[nx][ny] != '.')
				{
					jihoon[nx][ny] = tmp;
					continue;
				}
			}

			else
			{
				//cout << "jihoon : " << jihoon[nx][ny] << " fire : " << fire[nx][ny] << endl;
				//cout << "visited[nx][ny] : " << visited[nx][ny] << endl;
				/*
				for (int i = 0; i < R; i++)
				{
					for (int j = 0; j < C; j++)
					{
						cout << jihoon[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				*/
				if (visited[nx][ny] == 1 || board[nx][ny] != '.')
				{
					jihoon[nx][ny] = tmp;
					continue;
				}

			}

			jihoon[nx][ny] = jihoon[cur.first][cur.second] + 1;
			visited[nx][ny] = 1;
			q_jihoon.push({ nx,ny });
		}
	}
	/*
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << jihoon[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	*/
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (board[i][j] != 'F' &&  fire[i][j] >= jihoon[i][j]) board[i][j] = jihoon[i][j] + '0';
			else if(fire[i][j] == -1 && jihoon[i][j] != 0) board[i][j] = jihoon[i][j] + '0';
		}
	}
	/*
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	*/
	string answer;
	int min = 100000;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (i == 0 || i == R - 1)
			{
				if (board[i][j] != '0' && board[i][j] != '#' && board[i][j] != '.' && board[i][j] != 'F' && board[i][j] != 'J')
				{
					min = board[i][j] - '0' < min ? board[i][j] - '0' : min;
				}

			}
			if (j == 0 || j == C - 1)
			{
				if (board[i][j] != '0' && board[i][j] != '#' && board[i][j] != '.' && board[i][j] != 'F' && board[i][j] != 'J')
				{
					min = board[i][j] - '0' < min ? board[i][j] - '0' : min;
				}

			}
		}
	}
	if (min == 100000) cout << "IMPOSSIBLE";
	else cout << min;
}
