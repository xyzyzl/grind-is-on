#include <bits/stdc++.h>

using namespace std;


int main()
{
	freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);
	int N, K;
	cin >> N >> K;
	int dp[N], arr[N];
	for(int i = 0; i < N; i++)
	{
		dp[i] = 0;
		cin >> arr[i];
	}
	dp[0] = arr[0];
	// cout << dp[N-1] << endl;
	for(int i = 1; i < N; i++)
	{
		int mx = arr[i];
		for(int j = i; i-j+1<=K; j--)
		{
			mx = max(mx, arr[j]);
			if(j == 0)
			{
				dp[i] = max(dp[i], mx*(i-j+1));
				break;
			}
			else
				dp[i] = max(dp[i], dp[j-1]+mx*(i-j+1));
		}
	}
	cout << dp[N-1] << endl;
}
