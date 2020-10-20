
// set 활용 --> 시간초과
/*
#include <bits/stdc++.h>
using namespace std;

set<long long int> note1;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int T, N, M;
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			long long int num;
			cin >> num;
			note1.insert(num);
		}
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			long long int cmp;
			cin >> cmp;
			if (note1.count(cmp) == 1) cout << "1\n";
			else cout << "0\n";
		}
		note1.clear();
	}
}
*/

// binary search
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int T, N, M;
	int left, right; //left는 처음 값, right는 끝 값
	int num; //찾는 범위에 각각의 원소, 넣을 수와 찾을 수의 해당하는 원소

	cin >> T;
	while (T--) {
		vector<int> v1, v2; //v1는 찾는 범위, v2는 찾는 수

		//찾는 범위와 찾는 수를 최신화
		cin >> N;
		while (N--) {
			cin >> num;
			v1.push_back(num);
		}
		cin >> M;
		while (M--) {
			cin >> num;
			v2.push_back(num);
		}

		sort(v1.begin(), v1.end()); //이분탐색을 위한 정렬

		//이분탐색 구현, 중앙값이 찾는 수면 flag를 true로 반환
		//중앙갑이 찾는 값보다 작으면 left를 mid + 1로 옮기고, 중앙값이 찾는 값보다 크면 right를 mid - 1로 옮긴다.
		for (int j = 0; j < v2.size(); j++) {
			bool flag = false;
			left = 0;
			right = v1.size() - 1;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (v2[j] == v1[mid]) {
					flag = true;
					break;
				}
				if (v2[j] > v1[mid]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			cout << flag << '\n'; //찾은 결과를 출력
		}
	}
}
