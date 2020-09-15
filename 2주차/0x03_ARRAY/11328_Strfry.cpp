#include <bits/stdc++.h>
using namespace std;

int arr[26];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	while (N != 0)
	{
		string str1, str2;
		cin >> str1 >> str2;
		for (int i = 0; i < str2.size(); i++)
		{
			arr[str2[i] - 'a']++;
		}
		for(int i = 0; i<str1.size();i++)
			arr[str1[i] - 'a']--;

		for (int i = 0; i < 26; i++)
		{
			if (arr[i] != 0)
			{
				cout << "Impossible\n";
				break;
			}
			if (i == 25) cout << "Possible\n";
		}
		memset(arr, 0, sizeof arr);
		N--;
	}
}