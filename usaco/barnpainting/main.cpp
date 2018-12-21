#include <bits/stdc++.h>

#define ll long long

#define MAXN 100005
#define MOD 1000000007

using namespace std;

int N, K;
vector<int> adj_lst[MAXN];
int arr[MAXN];
ll dp[MAXN][3]; // vertex, color of vertex
bool vis[MAXN];
ll betaji(int v, int c, int pv, int pc)
{
	if(c == pc || (arr[v] >= 0 && c != arr[v]))
	{
		// cout << "h" << endl;
		return 0;
	}
	if(dp[v][c] >= 0)
		return dp[v][c];
	dp[v][c] = 1;
	for(int nv : adj_lst[v])
	{
		if(nv == pv)
			continue;
		int ways = 0;
		for(int nc = 0; nc < 3; nc++)
		{
			ways += betaji(nv, nc, v, c);
			ways %= MOD;
		}
		dp[v][c] *= ways;
		dp[v][c] %= MOD;
	}
	return dp[v][c];
}
int main()
{
	freopen("barnpainting.in", "r", stdin);
	freopen("barnpainting.out", "w", stdout);
	for(int i = 0; i < MAXN; i++)
		for(int j = 0; j < 3; j++)
			dp[i][j] = -1;
	cin >> N >> K;
	for(int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj_lst[a].push_back(b);
		adj_lst[b].push_back(a);
	}
	fill(arr, arr+N, -1);
	for(int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		arr[a] = b;
	}
	ll ans = betaji(0, 0, -1, -1);
	ans = (ans+betaji(0, 1, -1, -1)) % MOD;
	ans = (ans+betaji(0, 2, -1, -1)) % MOD;
	cout << ans << endl;
}