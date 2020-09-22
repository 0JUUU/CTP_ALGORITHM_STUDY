#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int K, a, sum = 0;
	stack<int> s;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> a;
		if (a == 0) s.pop();
		else s.push(a);
	}
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	cout << sum;

}