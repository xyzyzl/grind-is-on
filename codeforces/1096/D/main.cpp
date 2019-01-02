#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
string prob, key = "ihard";
ll a[100005];
ll dp[5]; // min ambiguity for each h, a, r, d
int main()
{
	cin >> n >> prob;
	prob = "i" + prob;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dp[0] = LLONG_MAX;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 4; j++)
			if(prob[i] == key[j])
				dp[j] = min(dp[j-1], a[i] + dp[j]);
	cout << dp[4] << endl;
}
