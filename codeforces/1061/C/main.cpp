#include <bits/stdc++.h>

#define int long long
using namespace std;

#define MAXN 1000005
#define MOD 1000000007
typedef pair<int, int> pii;
#define f first
#define s second

int n;
int a[MAXN];
int dp[MAXN];
#undef int
int main()
#define int long long
{
	cin >> n;
	dp[0] = 1;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		vector<int> divs;
		for(int j = 1; j <= (int)sqrt(a[i]); j++)
		{
			if(a[i] % j == 0)
			{
				divs.push_back(j);
				if(j != a[i]/j)
					divs.push_back(a[i]/j);
			}
		}
		sort(divs.begin(), divs.end());
		reverse(divs.begin(), divs.end());
		for(int div : divs)
		{
			dp[div] = (dp[div] + dp[div-1]) % MOD;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans = (ans + dp[i]) % MOD;
	}
	ans %= MOD;
	cout << ans << endl;
}
