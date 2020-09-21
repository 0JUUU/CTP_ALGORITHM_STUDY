#include <bits/stdc++.h>
using namespace std;

list<int> circular;
vector<int> out;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N, K, count = 0;
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++)
	{
		circular.push_back(i);
	}

	cout << "<";
	list<int>::iterator it = circular.begin();
	while (!circular.empty())
	{
		count++;
		if (count == K)
		{
			if (circular.size() != 1)
				cout << *it << ", ";
			else cout << *it;
			it = circular.erase(it);
			if (it == circular.end()) it = circular.begin();
			count = 0;
		}
		else
		{
			if (it == --circular.end()) it = circular.begin();
			else it++;
		}
			
	
	}
	cout << ">";
}