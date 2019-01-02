#include <bits/stdc++.h>

using namespace std;

bool is_palin(char s[1000], int N)
{
	for(int i = 0; i <= N/2; i++)
	{
		if(s[i] != s[N-i-1])
			return false;
	}
	return true;
}

int main()
{
	int t;
	cin >> t;
	for(int c = 0; c < t; c++)
	{
		char s[1000];
		string _s;
		cin >> _s;
		int N = _s.length();
		// cout << N << endl;
		for(int i = 0; i < N; i++)
		{
			s[i] = _s[i];
		}
		sort(s, s+N);
		// cout << is_palin(s, N) << endl;
		if(is_palin(s, N))
			cout << "-1" << endl;
		else
		{
			for(int i = 0; i < N; i++)
				cout << s[i];
			cout << endl;
		}
	}
}
