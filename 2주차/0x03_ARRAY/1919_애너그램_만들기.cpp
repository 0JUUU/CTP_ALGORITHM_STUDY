#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s1, s2;
	int count = 0;
	cin >> s1 >> s2;

	for (int i = 0; i < s1.size(); i++)
	{
		arr[s1[i] - 'a']++;
	}

	for (int i = 0; i < s2.size(); i++)
	{
		arr[s2[i] - 'a']--;
	}

	for (int i = 0; i < 26; i++)
	{
		if (arr[i] != 0) count += abs(arr[i]);
	}
	cout << count;
}