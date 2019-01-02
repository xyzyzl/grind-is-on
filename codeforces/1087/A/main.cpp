#include <bits/stdc++.h>

#define OST N/2
#define EST N/2-1

using namespace std;

map<int, int> mp;
string s;
string res;

int main()
{
	cin >> s;
	int N = s.length();
	// if N is odd, original position is N/2.
	// if N is even, original position is N/2-1.
	// loop through and add
	if(N%2)
	{
		// odd
		int ct = 0;
		res += s[ct+OST];
		ct++;
		while(ct+OST < N)
		{
			res += s[OST+ct];
			res += s[OST-ct];
			ct++;
		}
		cout << res << endl;
	} else
	{
		// even
		int ct = 0;
		res += s[ct+EST];
		// cout << res << endl;
		ct++;
		while(ct+EST<N-1)
		{
			res += s[EST+ct];
			res += s[EST-ct];
			// cout << res << endl;
			ct++;
		}
		res += s[N-1];
		cout << res << endl;
	}
}
