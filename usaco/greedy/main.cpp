#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int n;
int arr[MAXN];
// int mni[MAXN];
bool good(int k)
{
	int num[MAXN]; // num[index the cow falls back to]
	for(int i = 1; i <= n; i++)
		num[i] = 0;
	for(int i = 0; i < k-1; i++)
		num[arr[i]]++;
	int tot = 0;
	for(int i = 1; i <= n; i++)
	{
		tot += num[i];
		if(tot >= i)
			return false; // can't get gift
	}
	return true; // can get gift
}
int main()
{
	freopen("greedy.in", "r", stdin);
	freopen("greedy.out", "w", stdout);
	cin >> n;
	// mni[0] = INT_MAX;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		// mni[i] = min(mni[i-1], arr[i]);
		arr[i] = n-arr[i];
	}
	int lo = 1, hi = n+1;
	while(lo + 1 < hi)
	{
		int mid = (lo+hi)/2;
		if(good(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << (n-lo) << endl;
}
