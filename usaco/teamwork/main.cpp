#include <bits/stdc++.h>

#define MAXN 10005
#define MAXK 1005

using namespace std;

int n, k;
int s[MAXN], dp[MAXN];
int main()
{
	freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	dp[0] = s[0];
	for(int i = 1; i < n; i++)
	{
		int mx = s[i];
		for(int j = i; j >= 0 && i-j+1 <= k; j--)
		{
			mx = max(mx, s[j]);
			if(j == 0)
				dp[i] = max(dp[i], mx*(i-j+1));
			else
				dp[i] = max(dp[i], dp[j-1] + mx*(i-j+1));
		}
	}
	cout << dp[n-1] << endl;
}
