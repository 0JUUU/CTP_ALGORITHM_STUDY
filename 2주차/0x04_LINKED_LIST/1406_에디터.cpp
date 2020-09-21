#include <bits/stdc++.h>
using namespace std;

// Using STL LIST
/*
int main()
{
	string s1;
	list<char> s2;
	int M;
	cin >> s1 >> M;
	int N = s1.size();
	s2.push_back('-');
	for (int i = 0; i < N; i++)
	{
		s2.push_back(s1[i]);
	}

	list<char>::iterator curser = --s2.end();

	int* command = new int[M];
	for (int i = 0; i < M; i++) 
	{
		char c, $;
		cin >> c; 
		switch (c)
		{
		case 'L':
			if (curser != s2.begin())
				curser--;			
			break;
		case 'D':
			if (curser != --s2.end())
				curser++;				
			break;
		case'B':
			if (*curser != '-' && curser != s2.end())
			{
				s2.erase(curser--);
				if (curser == s2.end()) --curser;
			}
			break;
		case 'P':
			cin >> $;
			if (curser != s2.end())
				curser = s2.insert(++curser, $);
			break;
		default:
			break;
		}
	}

	for (auto it = ++s2.begin(); it != s2.end(); it++)
	{
		cout << *it;
	}
}
*/

//Using unlicensed LIST
const int MX = 1200000;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;
int curser;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);

	string s1;
	int M;
	cin >> s1 >> M;
	int N = s1.size();
	for (int i = 0; i < N; i++)
	{
		dat[unused] = s1[i];
		if (unused != N)
		{
			nxt[i] = unused;
			pre[unused] = i;
		}
		else 
		{
			nxt[i] = unused;
			nxt[unused] = -1;
			pre[unused] = i;
		}
		unused++;
	}
	curser = unused - 1;

	for (int i = 0; i < M; i++) 
	{
		char c, $;
		cin >> c;
		switch (c)
		{
		case 'L':
			if (curser != 0) curser = pre[curser];
			break;
		case 'D':
			if(nxt[curser] != -1) curser = nxt[curser];
			
			break;
		case 'B':
			if (pre[curser] != -1)
			{
				if (nxt[curser] != -1)   pre[nxt[curser]] = pre[curser];
				nxt[pre[curser]] = nxt[curser];
				curser = pre[curser];
			}
			break;
		case 'P':
			cin >> $;
			dat[unused] = $;
			pre[unused] = curser;
			nxt[unused] = nxt[curser];
			if (nxt[curser] != -1) pre[nxt[curser]] = unused;
			nxt[curser] = unused;

			curser = unused;
			unused++;
			break;
		}
	}

	int cur = nxt[0];
	while (cur != -1) {
		cout << dat[cur];
		cur = nxt[cur];
	}
	cout << "\n\n";
}
