/*
ID: albert.28
TASK: shopping
LANG: C++11
*/

#include <bits/stdc++.h>

#define MAX 1000
#define MAXN 6

using namespace std;

int s, b, cnt;
int offers[MAX][MAXN];
int codes[MAX], disc[MAX]; // codes is a map which maps indices
int qty[MAXN];
int dp[MAXN][MAXN][MAXN][MAXN][MAXN];
void do_something(int ind)
{
		int a = offers[ind][0];
		int b = offers[ind][1];
		int c = offers[ind][2];
		int d = offers[ind][3];
		int e = offers[ind][4];
		for(int i = 0; i+a <= qty[0]; i++)
			for(int j = 0; j+b <= qty[1]; j++)
				for(int k = 0; k+c <= qty[2]; k++)
					for(int l = 0; l+d <= qty[3]; l++)
						for(int m = 0; m+e <= qty[4]; m++)
							dp[i+a][j+b][k+c][l+d][m+e] = min(dp[i+a][j+b][k+c][l+d][m+e], dp[i][j][k][l][m] + disc[ind]);
}
int main()
{
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
	cin >> s;
	// cout << s << endl;
	fill(codes, codes+MAX, -1);
	for(int i = 0; i < s; i++)
	{
		int n;
		cin >> n;
		for(int j = 0; j < n; j++)
		{
			int code;
			cin >> code;
			if(codes[code] == -1)
				codes[code] = cnt++;
			int _qty;
			cin >> _qty;
			offers[i][codes[code]] = _qty;
		}
		cin >> disc[i]; // discount price for each offer
	}
	// cout << "hi" << endl;
	
	cin >> b;
	// cout << b << endl;
	for(int i = 0; i < b; i++)
	{
		int code;
		cin >> code;
		if(codes[code] == -1)
		{
			codes[code] = cnt++;
		}
		cin >> qty[codes[code]];
		cin >> disc[s+i]; // real prices
		offers[s+i][codes[code]] = 1;
	}
	memset(dp, 127, sizeof(dp));
	dp[0][0][0][0][0] = 0;
	for(int i = 0; i < s+b; i++)
	{
		do_something(i);
	}
	cout << dp[qty[0]][qty[1]][qty[2]][qty[3]][qty[4]] << endl;
}
