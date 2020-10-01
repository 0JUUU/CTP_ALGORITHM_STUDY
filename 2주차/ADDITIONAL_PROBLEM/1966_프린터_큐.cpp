#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	int test_case;
	cin >> test_case;
	while (test_case--)
	{
		int N, M, count = 0;
		cin >> N >> M;
		queue<pair<int, int>> q;
		vector<int> score;
		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			score.push_back(a);
			q.push(make_pair(i, a));
		}
		sort(score.begin(), score.end(),greater<int>());
		vector<int>::iterator it = score.begin();

		while (1)
		{
			if (*it == q.front().second)
			{
				count++;
				if (q.front().first == M)
				{
					break;
				}
				it = score.erase(it);
				q.pop();
			}
			else
			{
				q.push(q.front());
				q.pop();
			}
		}
		cout << count << "\n";
	}
}