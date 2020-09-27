#include <bits/stdc++.h>
using namespace std;

// LITTLE BIT,,, MESSY
/*
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	stack<char> line;
	int cut = 0, stick = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			line.push('(');
		}
		else if (s[i] == ')')
		{
			if (s[i - 1] == '(')
			{
				line.pop();
				cut += line.size();
			}
			else if (i != s.size() - 1 && s[i + 1] == '(')
			{
				stick++;
				cut += stick;
				while (stick--)
				{
					line.pop();
				}
				stick = 0;
			}
			else if (i == s.size() - 1) cut += stick + 1;
			else
			{
				stick++;
			}
				
		}
	}
	cout << cut;
}
*/

// THINK MORE
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	stack<char> line;
	char prev = s[0];
	int total = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(') line.push(s[i]);
		else if (s[i] == ')')
		{
			if (prev == ')')
			{
				if (!line.empty())
				{
					total++;
					line.pop();
				}
			}
			else
			{
				if (!line.empty())
				{
					line.pop();
					total += line.size();
				}
			}
		}
		prev = s[i];
	}
	cout << total;
}