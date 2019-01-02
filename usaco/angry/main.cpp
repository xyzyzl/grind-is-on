#include <bits/stdc++.h>

#define ll long long

#define MAXN 50000

using namespace std;

int n;
ll arr[MAXN];
ll best_l[MAXN], best_r[MAXN]; // smallest radius that propagates through
// both sides
int main()
{
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		arr[i] *= 2;
	}
	sort(arr, arr+n);
	fill(best_l, best_l+n, 1500000000);
	fill(best_r, best_r+n, 1500000000);
	best_l[0] = -2;
	best_r[n-1] = -2;
	int j = 0;
	for(int i = 1; i < n; i++)
	{
		while(j+1 < i && abs(arr[i]-arr[j+1]) > best_l[j+1] + 2)
			j++;
		// cout << best_l[j+1] + 2 << endl;
		best_l[i] = min(abs(arr[i]-arr[j]), best_l[j+1] + 2);
		// cout << best_l[i] << endl;
	}
	j = n-1;
	for(int i = n-2; i >= 0; i--)
	{
		while(j-1 > i && abs(arr[j-1]-arr[i]) > best_r[j-1] + 2)
			j--;
		best_r[i] = min(abs(arr[j]-arr[i]), best_r[j-1] + 2);
	}
	int lo = 0, hi = n-1;
	ll ans = 1500000000;
	while(lo != hi)
	{
		ans = min(ans, max((arr[hi] - arr[lo])/2, 2+max(best_l[lo], best_r[hi])));
		if(best_l[lo + 1] < best_r[hi - 1])
			lo++;
		else
			hi--;
	}
	// cout << ans << endl;
	double num = (double) ans;
	cout << setprecision(1) << fixed << ans/2.0 << endl;
}
