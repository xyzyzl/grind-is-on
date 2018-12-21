#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

int n;
int arr[256];
int dp[256][256];
int main()
{
	freopen("248.in", "r", stdin);
	freopen("248.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i][i] = arr[i];
	}
	int mx = 0;
	for(int len = 2; len <= n; len++)
		for(int i = 1; i+len-1 <= n; i++)
		{
			int j = i+len-1;
			dp[i][j] = 0;
			for(int k = i; k < j; k++)
			{
				if(dp[i][k] == dp[k+1][j] && dp[i][k] > 0)
				{
					// cout << dp[i][k] << endl;
					dp[i][j] = max(dp[i][j], dp[i][k] + 1);
				}
			}
			// cout << dp[i][j] << endl;
			mx = max(mx, dp[i][j]);
		}
	cout << mx << endl;
}
