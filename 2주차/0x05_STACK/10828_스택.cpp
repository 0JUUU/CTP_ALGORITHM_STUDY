#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N, a;	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string command;
		cin >> command;
		if (command == "push")
		{
			cin >> a;
			s.push(a);
		}
		else if (command == "pop")
		{
			if (!s.empty())
			{
				cout << s.top()<<endl;
				s.pop();
			}
				
			else cout << -1 << endl;
		}
		else if (command == "size")
		{
			cout << s.size() << endl;
		}
		else if (command == "empty")
		{
			if (!s.empty()) cout << 0 << endl;
			else cout << 1 << endl;
		}
		else if (command == "top")
		{
			if (!s.empty())
				cout << s.top() << endl;

			else cout << -1 << endl;
		}
		else { }
	}
}