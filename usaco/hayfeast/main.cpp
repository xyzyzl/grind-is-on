#include <bits/stdc++.h>

#define MAXN 100005

#define ll long long

using namespace std;

int N;
ll M, f[MAXN], fsum[MAXN], s[MAXN];
multiset<ll> st; // where each spiciness shows up in the interval, and the largest one
int main()
{
	freopen("hayfeast.in", "r", stdin);
	freopen("hayfeast.out", "w", stdout);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> f[i] >> s[i];
	}
	int l = 0;
	int r = 0;
	ll fl = 0, ans = LLONG_MAX;
	while (r <= N)
	{
		if (fl < M)
		{
			st.insert(s[r]);
			fl += f[r++];
		} else
		{
			ans = min(ans, *st.rbegin()); // minimum maximum spice
			st.erase(st.find(s[l]));
			fl -= f[l++];
		}
	}
	cout << ans << endl;
}