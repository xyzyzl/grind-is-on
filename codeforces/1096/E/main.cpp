#include <bits/stdc++.h>

#define MAXN 200005
#define MOD 998244353

using namespace std;

int n;
int arr[MAXN];
bool known[MAXN];

int modInverse(int a, int m) 
{ 
	a = a%m; 
	for (int x=1; x<m; x++) 
		if ((a*x) % m == 1) 
			return x; 
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
