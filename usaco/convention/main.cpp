#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

#define mp make_pair
#define pb push_back
#define    ll long long
#define INF (1e9*1)+5
#define LL_INF (1e18*1)+5
#define bitinc(s) (s&-s)

typedef pair<int, int> pii;
#define f first
#define s second

int n, m, c;
ll arr[MAXN];

bool funciona(int mid)
{
	int bus = 1;
	int t = arr[0];
	int ind = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] - t > mid || i + 1 - ind > c)
		{
			bus++;
			t = arr[i];
			ind = i;
		}
	}
	return bus <= m;
}

int main()
{
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	ll lo = 0;
	ll hi = (ll) 1e9;
	while (lo != hi)
	{
		int mid = (lo + hi) / 2;
		if (funciona(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	cout << hi << endl;
}