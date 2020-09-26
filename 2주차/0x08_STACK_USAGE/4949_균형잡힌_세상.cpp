#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	while (1)
	{
		string answer = "yes";
		stack<char> correct;
		getline(cin, s);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '[')
			{
				correct.push(s[i]);
			}
			else if (s[i] == ')')
			{
				if (correct.empty())
				{
					answer = "no";
					break;
				}
				else if (correct.top() == '(') correct.pop();
				else
				{
					answer = "no";
					break;
				}
			}
			else if (s[i] == ']')
			{
				if (correct.empty())
				{
					answer = "no";
					break;
				}
				else if (correct.top() == '[') correct.pop();
				else
				{
					answer = "no";
					break;
				}
			}
			else {}
		}
		if (!correct.empty()) answer = "no";
		if (s == ".") break;
		cout << answer << "\n";
	}
}