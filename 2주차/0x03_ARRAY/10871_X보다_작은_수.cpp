#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N, X, a;
	cin >> N >> X;
	for (int i = 0; i < N;i++)
	{
		cin >> a;
		if (a < X) cout << a <<  " ";
	}
}