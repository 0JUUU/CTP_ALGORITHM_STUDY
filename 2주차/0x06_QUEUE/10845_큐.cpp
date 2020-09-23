#include <bits/stdc++.h>
using namespace std;

// USE STL QUEUE
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	int N;
//	cin >> N;
//	queue<int> q;
//
//	for (int i = 0; i < N; i++)
//	{
//		string s;
//		cin >> s;
//		if (s == "push")
//		{
//			int X;
//			cin >> X;
//			q.push(X);
//		}
//		else if (s == "pop")
//		{
//			if (!q.empty())
//			{
//				cout << q.front() << "\n";
//				q.pop();
//			}
//			else cout << "-1\n";
//		}
//		else if (s == "size")
//		{
//			cout << q.size() << "\n";
//		}
//		else if (s == "empty")
//		{
//			if (q.empty()) cout << "1\n";
//			else cout << 0 << "\n";
//		}
//		else if (s == "front")
//		{
//			if (!q.empty())
//			{
//				cout << q.front() << "\n";
//			}
//			else cout << -1 << "\n";
//		}
//		else if (s == "back")
//		{
//			if (!q.empty())
//			{
//				cout << q.back() << "\n";
//			}
//			else cout << -1 << "\n";
//		}
//		else {}
//	}
//}

// USING SELF-MADE
const int MX = 10000;
int dat[MX];
int head = 0, tail = 0;

void push(int x) {
	if (tail == MX)
	{
		tail = 0;
		dat[tail] = x;
	}
	else
	{
		dat[tail] = x;
		tail++;
	}
}
void pop() {
	cout << dat[head] << "\n";
	head++;
	if (head == MX) head = 0;
}
int front() {
	return dat[head];
}

int back() {
	return dat[tail - 1];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int X;
			cin >> X;
			push(X);
		}
		else if (s == "pop")
		{
			if (head != tail)
			{
				pop();
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
			if (head == tail) cout << "-1\n";
			else cout << front() << "\n";
		}
		else if (s == "back")
		{
			if (head == tail) cout << "-1\n";
			else cout << back() << "\n";
		}
		else {}
	}

}