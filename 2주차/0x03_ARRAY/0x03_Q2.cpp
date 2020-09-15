#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int N)
{
	// O(N^2) 풀이방식
	//for (int i = 0; i < N; i++)
	//{
	//	if (arr + i < find(arr, arr + N, 100 - arr[i]) && find(arr, arr + N, 100 - arr[i]) < arr + N)
	//	{
	//		cout << 1 << "\n";
	//		return;
	//	}
	//}
	//cout << 0 << "\n";
	//return;

	// O(N) 풀이방식
	int num[101] = {};	// 0 - 100
	for (int i = 0; i < N; i++)
	{
		if (num[100 - arr[i]] == 1)			// if ( num[100 - arr[i]])
		{
			return 1;
		}
		num[arr[i]] += 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int arr[] = { 1, 52, 48 };
	cout << func2(arr, 3) << endl; 

	int arr1[] = { 50,42 };

	cout << func2(arr1, 2) << endl;

	int arr2[] = { 4,13,63,87 };
	cout << func2(arr2, 4) << endl;

}