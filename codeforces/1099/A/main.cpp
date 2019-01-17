#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

pii u[2];
int main()
{
	int w, h, u1, d1, u2, d2;
	cin >> h >> w >> u1 >> d1 >> u2 >> d2;
	u[0] = make_pair(d1, u1);
	u[1] = make_pair(d2, u2);
	sort(u, u+2);
	int vis = 0;
	for(int i = h-1; i >= 0; i--)
	{
		w += i;
		if(u[vis].first == i)
			w -= u[i].second;
	}
	cout << w << endl;
}
