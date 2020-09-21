#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		string s1;
		cin >> s1;

		list<char> s2;
		int L = s1.size();
		list<char> ::iterator cursor = s2.begin();

		for (int i = 0; i < L; i++)
		{
			switch (s1[i])
			{
			case '<':
				if (cursor != s2.begin())
					cursor--;
				break;
			case '>':
				if (cursor != s2.end())
					cursor++;
				break;
			case '-':
				if (cursor != s2.begin())
				{
					cursor--;
					cursor = s2.erase(cursor);
				}
				break;
			default:
				s2.insert(cursor, s1[i]);
				break;
			}
		}

		for (auto i : s2)
			cout << i;
		cout << endl;
	}
}