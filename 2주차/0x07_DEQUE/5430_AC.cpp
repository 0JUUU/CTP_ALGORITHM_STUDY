#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string s, arr, answer = "\0";
		bool reverse = false;
		int n;
		deque<int> dq;
		cin >> s >> n >> arr;
		arr.erase(arr.begin() + 0);
		arr.erase(arr.begin() + arr.size() - 1);
		string num;
		stringstream ss(arr);
		while (getline(ss, num, ','))
			dq.push_back(atoi(num.c_str()));
	

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'R')
			{
				reverse = !reverse;
			}
			else if (s[i] == 'D')
			{
				if (dq.empty())
				{
					answer = "error";
					break;
				}
				if (reverse) dq.pop_back();
				else dq.pop_front();
			}
			else {}
		}

		if (answer != "error")
		{
			answer += "[";
			if (reverse)
			{
				while (!dq.empty())
				{
					answer += to_string(dq.back());
					dq.pop_back();
					if (!dq.empty()) answer += ",";
				}

			}
			else
			{
				while (!dq.empty())
				{
					answer += to_string(dq.front());
					dq.pop_front();
					if(!dq.empty()) 	answer += ",";

				}
			}

			answer += "]";
		}
		cout << answer << endl;
	}
}