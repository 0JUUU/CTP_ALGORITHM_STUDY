#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M, count = 0;
	cin >> N >> M;
	deque<int> dq;
	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	deque<int>::iterator head = dq.begin();
	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		if (dq.size() == 1) break;
		deque<int>::iterator index = find(dq.begin(), dq.end(), a);
		//cout << "*index : " << *index << endl;
		//cout << "dq.size() : " << dq.size() << endl;
		//cout << "abs(head- index) : " << abs(head - index) << endl;
		//cout << "dq.size() - abs(head - index) : " << dq.size() - abs(head - index) << endl;
		if ((abs(head - index)) > dq.size() - abs(head - index))
		{
			count += dq.size() - abs(head - index);
		}
		else count += abs(head - index);

		index = find(dq.begin(), dq.end(), a);
		if(index != dq.end()) index = dq.erase(index);
		if (index == dq.end()) index = dq.begin();
		head = index;
	}
	cout<<count<<"\n";
}