#include <bits/stdc++.h>
using namespace std;

int F, S, G, U, D;
int btn[1000001];
int visited[1000001];
int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> F >> S >> G >> U >> D;

	int dir[2] = { U, -D };
	queue<int> q;
	q.push(S);
	btn[S] = 0;
	visited[S] = 1;
	while(!q.empty())
	{
		int cur = q.front(); q.pop();
		
		for (int d = 0; d < 2; d++)
		{
			int nx = cur + dir[d];
			
			if (nx < 1 || nx > F) continue;
			if (visited[nx] == 1) continue;
			visited[nx] = 1;
			btn[nx] = btn[cur] + 1;
			q.push(nx);
		}
	}

	if (S == G) cout << 0;

	else
	{
		if (btn[G] == 0) cout << "use the stairs";
		else cout << btn[G];
	}

	
}