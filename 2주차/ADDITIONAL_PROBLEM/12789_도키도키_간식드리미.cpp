#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);	cin.tie(0);
	int N, cur = 1;
	queue<int> line;
	stack<int> wait;
	string answer;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		line.push(a);
	}

	while (cur <= N)
	{
		if (!line.empty())
		{
			if (!wait.empty() && cur == wait.top())
			{
				wait.pop();
				cur++;
				continue;
			}
			while (!line.empty() && cur != line.front())	// line�� ����ִ� ���¿��� ������ �����ϹǷ� empty���� Ȯ�� ����
			{												// �̰� ��¥ �� �ʼ�
				wait.push(line.front());
				line.pop();
			}
			if(!line.empty()) line.pop();
		}
		else if (!wait.empty())
		{
			if (cur == wait.top())
			{
				wait.pop();
			}
		}
		cur++;
		
	}
	if (wait.empty() && line.empty()) answer = "Nice";
	else answer = "Sad";
	cout << answer << "\n";

	return 0;
}