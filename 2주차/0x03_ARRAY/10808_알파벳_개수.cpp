#include <bits/stdc++.h>
using namespace std;

// 전역에 배열을 선언하면 알아서 0으로 초기화 --> memset / fill(alphabet, alphabet + 26, 0)을 사용할 필요 X
int alphabet[26];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	string S;
	cin >> S;

	//int alphabet[26];
	//memset(alphabet, 0, sizeof alphabet);
	
	// or
	//int alphabet[26] = {};

	for (int i = 0; i < S.size(); i++)
		alphabet[S[i] - 'a']++;

	for (int i : alphabet)
		cout << i << " ";
}