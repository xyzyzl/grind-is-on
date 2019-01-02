#include <bits/stdc++.h>

using namespace std;

int N, arr[105];
int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+N);
	int DUE_HOANG = 0;
	for(int i = 0; i < N; i += 2)
	{
		DUE_HOANG += (arr[i+1] - arr[i]);
	}
	cout << DUE_HOANG << endl;
}
