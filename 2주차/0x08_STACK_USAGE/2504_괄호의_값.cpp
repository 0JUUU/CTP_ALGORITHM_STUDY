#include <bits/stdc++.h>
using namespace std;
int X[100];

int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	string s;
	cin >> s;
	int cnt_left = 0, depth = 0;
	int answer = 0;
	stack<char> S;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '[')
		{
			S.push(s[i]);
			cnt_left++;
			depth++;
		}
			
		else if (s[i] == ')')
		{
			if (S.empty())
			{
				answer = 0;
				S.push(s[i]);
				break;
			}
			else if (S.top() == '(')
			{
				if (X[depth + 1] == 0) X[depth] += 2;
				else
				{
					X[depth + 1] *= 2;
					X[depth] += X[depth + 1];
					X[depth + 1] = 0;
				}

				S.pop();
				depth--;
			}
		}
		else if (s[i] == ']')
		{
			if (S.empty())
			{
				S.push(s[i]);
				answer = 0;
				break;
			}
			else if (S.top() == '[')
			{
				if (X[depth + 1] == 0) X[depth] += 3;
				else
				{
					X[depth + 1] *= 3;
					X[depth] += X[depth + 1];
					X[depth + 1] = 0;
				}

				S.pop();
				depth--;
			}
			else
			{
				S.push(s[i]);
				answer = 0;
				break;
			}
		}
	}
	if (!S.empty()) answer = 0;
	else answer = X[1];
	cout << answer << '\n';
}