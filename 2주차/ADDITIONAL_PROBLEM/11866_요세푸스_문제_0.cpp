#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	int N, K, count = 0;
	cin >> N >> K;
	string s;
	s.push_back('<');
	queue<int> q;
	for (int i = 0; i < N; i++)
	{
		q.push(i + 1);
	}
	while (!q.empty())
	{
		count++;
		if (K == count)
		{
			string inte = to_string(q.front());
			s += inte;
			q.pop();
			if (q.empty()) break;
			s += ", ";
			count = 0;
		}
		else
		{
			int a = q.front();
			q.pop();
			q.push(a);
		}
	}
	s.push_back('>');
	cout << s;
}