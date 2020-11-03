#include <bits/stdc++.h>
using namespace std;

// �� ���� �� ������ 0~100000�� ������ ��������
// ���Ҹ� ������ �����ؼ��� �ȵȴ�. 
// 0~200000 �� �� �ִ� ��Ȳ�� ����
int visited[100001];
int cnt[100001];

int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	int N, K;
	cin >> N >> K;
	int d_x[3] = { 1,-1,2 };
	queue<int> number;
	number.push(N);
	visited[N] = 1;
	while (!number.empty())
	{
		int cur = number.front();	number.pop();
		int next;

		for (int dir = 0; dir < 3; dir++)
		{
			
			if (d_x[dir] == 2) next = 2 * cur;
			else next = cur + d_x[dir];

			if (next < 0 || next > 100000) continue;

			if (visited[next] == 1) continue;

			cnt[next] += cnt[cur] + 1;
			visited[next] = 1;
			number.push(next);

			if (next == K) break;
		}

		if (next == K) break;
	}
	cout << cnt[K];
}