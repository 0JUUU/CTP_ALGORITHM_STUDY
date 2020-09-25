#include <bits/stdc++.h>
using namespace std;

// USING STL DEQUE
/*
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	deque<int> dq;
	for (int i = 0; i < N; i++)
	{
		string s;
		int X;
		cin >> s;
		if (s == "push_front")
		{
			cin >> X;
			dq.push_front(X);
		}
		else if (s == "push_back")
		{
			cin >> X;
			dq.push_back(X);
		}
		else if (s == "pop_front")
		{
			if (!dq.empty())
			{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else cout << "-1\n";
		}
		else if (s == "pop_back")
		{
			if (!dq.empty())
			{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else cout << "-1\n";
		}
		else if (s == "size")
		{
			cout << dq.size() << "\n";
		}
		else if (s == "empty")
		{
			if (dq.empty()) cout << "1\n";
			else cout << 0 << "\n";
		}
		else if (s == "front")
		{
			if (!dq.empty())
			{
				cout << dq.front() << "\n";
			}
			else cout << -1 << "\n";
		}
		else if (s == "back")
		{
			if (!dq.empty())
			{
				cout << dq.back() << "\n";
			}
			else cout << -1 << "\n";
		}
		else {}
	}
}
*/

// USING SELF-MADE
const int MX = 10001;
int dat[2 * MX + 1];
int head = MX, tail = MX;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		string s;
		int X;
		cin >> s;
		if (s == "push_front")
		{
			cin >> X;
			dat[--head] = X;
		}
		else if (s == "push_back")
		{
			cin >> X;
			dat[tail++] = X;
		}
		else if (s == "pop_front")
		{
			if (head != tail)
			{
				cout << dat[head] << "\n";
				head++;
			}
			else cout << "-1\n";
		}
		else if (s == "pop_back")
		{
			if (head != tail)
			{
				cout << dat[tail-1] << "\n";
				tail--;
			}
			else cout << "-1\n";
		}
		else if (s == "size")
		{
			cout << tail - head << "\n";
		}
		else if (s == "empty")
		{
			if (head == tail) cout << "1\n";
			else cout << 0 << "\n";
		}
		else if (s == "front")
		{
			if (head != tail)
			{
				cout << dat[head] << "\n";
			}
			else cout << -1 << "\n";
		}
		else if (s == "back")
		{
			if (head != tail)
			{
				cout << dat[tail-1] << "\n";
			}
			else cout << -1 << "\n";
		}
		else {}
	}
}