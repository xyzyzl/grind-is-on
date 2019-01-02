#include <bits/stdc++.h>
using namespace std;

#define MAXN 20
#define MAX 1100000
#define ll long long

typedef pair<int, int> pii;
#define f first
#define s second
typedef pair<int, pii> piii;

int N, h, mx=-1;
piii data[MAXN];
int dp[MAX], w[MAX];
int main()
{
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
	cin >> N >> h;
	for(int i = 0; i < N; i++)
	{
		int h, w, s;
		cin >> h >> w >> s;
		data[i] = make_pair(s+w, make_pair(h, w));
	}
	sort(data, data+N);
	reverse(data, data+N);
	for(int i = 1; i < (1 << N); i++)
	{
		ll ht = 0;
		int rem = INT_MAX;
		bool good = 1;
		for(int j = 0; j < N-1; j++)
		{
			rem = min(data[j].f, rem);
			rem -= data[j].s.s;
			h += (ll)data[j].s.f;
			if(rem < 0)
			{
				good=0;
				break;
			}
		}
		if(good && ht >= h)
			mx = max(mx, rem);
	}
	if(mx < 0)
	{
		cout << "Mark is too tall" << endl;
		return 0;
	}
	cout << mx << endl;
}
