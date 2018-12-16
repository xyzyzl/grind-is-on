#include <bits/stdc++.h>
// HCOONa Matata

#define int long long

using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

int N;
pii arr[50005];
int miny[50005], maxy[50005];
int mn2y[50005], mx2y[50005];

int solve()
{
	sort(arr, arr+N);
	/*
	for(int i = 0; i < N; i++)
		cout << arr[i].f << " " << arr[i].s << endl;
	*/
	fill(miny, miny+N, LLONG_MAX);
	fill(maxy, maxy+N, LLONG_MAX);
	miny[0] = arr[0].s;
	maxy[0] = arr[0].s;
	for(int i = 1; i < N; i++)
	{
		miny[i] = min(miny[i-1], arr[i].s);
		maxy[i] = max(maxy[i-1], arr[i].s);
		// cout << miny[i] << " " << maxy[i] << endl;
	}
	int area = (maxy[N-1] - miny[N-1])*(arr[N-1].f-arr[0].f);
	mn2y[N-1] = arr[N-1].s;
	mx2y[N-1] = arr[N-1].s;
	for(int i = N-2; i >= 0; i--)
	{
		mn2y[i] = min(mn2y[i+1], arr[i].s);
		mx2y[i] = max(mx2y[i+1], arr[i].s);
		// cout << mn2y[i] << " " << mx2y[i] << endl;
	}
	int mn = LLONG_MAX;
	for(int i = 0; i < N; i++)
	{
		// 0 to i, i+1 to N-1
		// cout << abs(arr[i].f - arr[0].f)*abs(maxy[i]-miny[i])+abs(arr[N - 1].f - arr[i+1].f)*abs(mx2y[i+1]-mn2y[i+1]) << endl;
		mn = min(mn, abs(arr[i].f - arr[0].f)*abs(maxy[i]-miny[i])+abs(arr[N - 1].f - arr[i+1].f)*abs(mx2y[i+1]-mn2y[i+1]));
		// cout << mn << endl;
	}
	return area - mn;
}

main()
{
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i].f >> arr[i].s;
	}
	int a1 = solve();
	for(int i = 0; i < N; i++)
	{
		int t = arr[i].f;
		arr[i].f = arr[i].s;
		arr[i].s = t;
	}
	int a2 = solve();
	cout << max(a1, a2) << endl;
}