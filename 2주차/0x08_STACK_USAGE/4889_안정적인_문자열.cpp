#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	int T = 1, count = 0;

	while (1)
	{
		stack<char> S;
		cin >> s;
		int left_cnt = 0, right_cnt = 0;

		if (!s.find("-"))
			return 0;
		// push char('{' / '}')
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '{')
				S.push(s[i]);
			else
			{
				if (S.empty())
					S.push(s[i]);
				else if (S.top() == '{')
					S.pop();
				else S.push('}');
			}
		}
		while (!S.empty())
		{
			if (S.top() == '{')
				left_cnt += 1;
			else right_cnt += 1;
			S.pop();
		}
		count += left_cnt / 2;
		left_cnt %= 2;
		count += right_cnt / 2;
		right_cnt %= 2;
		if (left_cnt == 1) count += 2;
		cout << T << ". " << count << '\n';
		T++;
		count = 0;
	}
}