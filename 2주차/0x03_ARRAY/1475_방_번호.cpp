#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int number[9];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string N;
	cin >> N;

	
	for (int i = 0; i < N.size(); i++)
	{
		int a = N[i] - '0';
		if (a == 9) number[6]++;
		else number[a]++;
	}
	if (max_element(number, number + 10) - number == 6)
	{
		if (*max_element(number, number + 10) % 2 == 0)
			cout << *max_element(number, number + 10) / 2;
		else
			cout << (*max_element(number, number + 10) / 2) + 1;
	}
	else
		cout << *max_element(number, number + 10);
	
}