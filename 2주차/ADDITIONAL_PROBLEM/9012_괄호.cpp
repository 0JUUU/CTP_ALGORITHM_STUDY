#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		string s, answer;
		cin >> s;
		stack<char> st;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				st.push(s[i]);
			else if (s[i] == ')')
			{
				if (!st.empty()) st.pop();
				else
				{
					st.push(s[i]);
					break;
				}
			}
		}
		if (!st.empty()) answer = "NO";
		else answer = "YES";
		cout << answer << endl;
	}
}