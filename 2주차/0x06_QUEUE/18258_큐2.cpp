#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	queue<int> q;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int X;
			cin >> X;
			q.push(X);
		}
		else if (s == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << "\n";
				q.pop();
			}
			else cout << "-1\n";
		}
		else if (s == "size")
		{
			cout << q.size() << "\n";
		}
		else if (s == "empty")
		{
			if (q.empty()) cout << "1\n";
			else cout << 0 << "\n";
		}
		else if (s == "front")
		{
			if (!q.empty())
			{
				cout << q.front() << "\n";
			}
			else cout << -1 << "\n";
		}
		else if (s == "back")
		{
			if (!q.empty())
			{
				cout << q.back() << "\n";
			}
			else cout << -1 << "\n";
		}
		else {}
	}
}