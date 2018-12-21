#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ll long long
typedef pair<int, int> pii;
#define f first
#define s second

bool good(int n, int k, int* w, int* t, int rat, ll* dp)
{
	for(int i = 0; i <= k; i++)
		dp[i] = -INF;
	dp[0] = 0;
	for(int i = 0; i < n; i++)
	{
		ll val = 1000*(ll)t[i] - rat*(ll)w[i];
		for(int j = k; j >= 0; j--)
		{
			int nxt = min(k, j+w[i]);
			if(dp[j] != -INF)
				dp[nxt] = max(dp[nxt], dp[j] + val);
		}
	}
	return dp[k] >= 0;
}

int main()
{
	freopen("talent.in", "r", stdin);
	freopen("talent.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int* w = new int[n];
	int* t = new int[n];
	for(int i = 0; i < n; i++)
	{
		cin >> w[i] >> t[i];
	}
	ll* dp = new ll[k+1];
	int lo = 0;
	int hi = (1000*250*1000); // maximum possible talent
	while(lo < hi)
	{
		// cout << lo << " " << hi << endl;
		int mid = (lo+hi+1)/2;
		if(good(n, k, w, t, mid, dp))
			lo = mid;
		else
			hi = mid-1;
	}
	cout << lo << endl;
}
