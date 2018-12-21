#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int N;
int arr[MAXN];
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];
	long long tot = 0;
	for(int i = 0; i <= N; i++)
	{
		tot += abs(arr[i+1]-arr[i]);
	}
	cout << (long long)ceil((long double)tot/2.0) << endl;
}