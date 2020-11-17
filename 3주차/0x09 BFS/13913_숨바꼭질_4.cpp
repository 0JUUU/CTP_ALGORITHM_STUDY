#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N, K;
int visited[200002];
int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> K;
	int dx[3] = { 1,-1,2 };
	queue<int> q;
	q.push(N);
	fill(visited, visited + 200002, -1);
	visited[N] = 0;
	vector<int> v;
	while (!q.empty())
	{
		if (q.front() == K) break;
		int cur = q.front();	q.pop();
		int nx;
		for (int dir = 0; dir < 3; dir++)
		{

			if (dir == 2) nx = 2 * cur;
			else nx = cur + dx[dir];

			if (nx < 0 || nx > 200002) continue;
			if (visited[nx] != -1) continue;

			visited[nx] = cur;
			q.push(nx);
			if (nx == K) break;
		}
		if (nx == K) break;
	}
	v.push_back(K);

	int a = K;
	while (a != N)
	{
		v.push_back(visited[a]);
		a = visited[a];
	}
	cout << v.size() - 1 << "\n";

	reverse(v.begin(), v.end());
	for (auto i : v)
		cout << i << " ";
}