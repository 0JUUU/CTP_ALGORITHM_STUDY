#include <bits/stdc++.h>
using namespace std;

map<string, int> player;

int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);

	int N;
	cin >> N;

	string name;
	for (int i = 0; i < N; i++)
	{
		cin >> name;
		player[name] ++;
	}
	
	for (int i = 0; i < N - 1; i++)
	{
		cin >> name;
		player[name]--;
	}
	map<string, int> ::iterator it = player.begin();
	for (; it != player.end(); it++)
	{
		if (it->second == 1)
		{
			cout << it->first;
			break;
		}
	}
}