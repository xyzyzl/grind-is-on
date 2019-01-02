#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
ll b[100005], a[200010];
int main()
{
	cin >> n;
	for(int i = 0; i < n/2; i++)
		cin >> b[i];
	a[0] = 0;
	a[n-1] = b[0];
	for(int i = 1; i < n/2; i++)
	{
		if(b[i] <= b[i-1])
		{
			a[i] = a[i-1];
		} else
		{
			a[i] = a[i-1] + (b[i]-b[i-1]);
		}
		a[n-i-1] = b[i]-a[i];
	}	
	for(int i = 0; i < n-1; i++)
		cout << a[i] << " ";
	cout << a[n-1] << endl;
}
