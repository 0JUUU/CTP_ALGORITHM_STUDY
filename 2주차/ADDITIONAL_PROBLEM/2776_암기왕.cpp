
// set Ȱ�� --> �ð��ʰ�
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
	int left, right; //left�� ó�� ��, right�� �� ��
	int num; //ã�� ������ ������ ����, ���� ���� ã�� ���� �ش��ϴ� ����

	cin >> T;
	while (T--) {
		vector<int> v1, v2; //v1�� ã�� ����, v2�� ã�� ��

		//ã�� ������ ã�� ���� �ֽ�ȭ
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

		sort(v1.begin(), v1.end()); //�̺�Ž���� ���� ����

		//�̺�Ž�� ����, �߾Ӱ��� ã�� ���� flag�� true�� ��ȯ
		//�߾Ӱ��� ã�� ������ ������ left�� mid + 1�� �ű��, �߾Ӱ��� ã�� ������ ũ�� right�� mid - 1�� �ű��.
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
			cout << flag << '\n'; //ã�� ����� ���
		}
	}
}
