#include <bits/stdc++.h>

using namespace std;

int n, k;
int main()
{
	int T;
	cin >> T;
	for(int DUEHOANG = 0; DUEHOANG < T; DUEHOANG++)
	{
		string str = "";
		cin >> n >> k;
		for(int i = 0; i < n; i++)
		{
			str += ('a'+i%k);
		}
		cout << str << endl;
	}
}
