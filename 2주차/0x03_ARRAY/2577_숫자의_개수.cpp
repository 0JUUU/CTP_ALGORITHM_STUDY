#include <bits/stdc++.h>
using namespace std;

int arr[10];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int A, B, C;
	cin >> A >> B >> C;

	int sum = A * B;
	sum *= C;
	string s = to_string(sum);
	for (int i = 0; i < s.size(); i++)
	{
		arr[s[i] - '0']++;
	}
	for (int i = 0; i <= 9; i++)
		cout << arr[i] << endl;
}