#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	int N, M;
	cin >> N >> M;

	vector<string> monster;
	map<string, string> print_int;
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		monster.push_back(s);
		print_int.insert(make_pair(s, to_string(i)));
	}
	vector<string> answer;
	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		if ('0' <= s[0] && s[0] <= '9')
		{
			cout << monster[stoi(s) - 1] << endl;
		}
		else
		{
			cout << print_int[s] << endl;
		}
	}
	for (auto i : answer)
		cout << i << endl;
}