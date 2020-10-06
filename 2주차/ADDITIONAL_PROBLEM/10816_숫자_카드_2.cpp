#include <bits/stdc++.h>
using namespace std;

vector<int> num;
int main()
{
	ios::sync_with_stdio;	 cin.tie(0);
	int N, M;
	cin >> N;
	
	vector<int> answer;
	num.resize(20000002, 0);
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		num[a + 10000000]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		answer.push_back(num[a+ 10000000]);
	}
	for (auto i : answer)
		cout << i << " ";

}