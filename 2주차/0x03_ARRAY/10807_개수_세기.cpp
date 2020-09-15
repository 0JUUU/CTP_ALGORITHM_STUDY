#include <bits/stdc++.h>
using namespace std;

int arr[201];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		arr[a + 100] ++;
	}
	int v;
	cin >> v;
	cout << arr[v + 100];
}