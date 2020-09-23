#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N, max = 0;
	cin >> N;
	vector<int> recv;
	vector<int> tower;
	recv.resize(N);
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		if (a > max) max = a;
		tower.push_back(a);
	}
	tower[0] = 0;
	
	for (int i = N - 1; i >= 1; i--)
	{
		if (tower[i] == max) recv[i] = 0;
		else
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (tower[i] <= tower[j])
				{
					recv[i] = j + 1;
					break;
				}
				recv[i] = 0;
			}
		}

	}
	for (auto i : recv)
		cout << i << " ";
}