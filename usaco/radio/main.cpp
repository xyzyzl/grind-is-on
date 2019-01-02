#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

int N, M, dp[1005][1005];
vector<pii> b, j;

void move(int &x, int &y, char dir)
{
	switch (dir)
	{
		case 'N': y++; break;
		case 'S': y--; break;
		case 'E': x++; break;
		case 'W': x--; break;
	}
}

int solve(int bind, int jind)
{
	int dist = (j[jind].f-b[bind].f)*(j[jind].f-b[bind].f) + 
		(j[jind].s-b[bind].s)*(j[jind].s-b[bind].s);
	if(bind+1 >= b.size() && jind+1 >= j.size())
		return dist;
	if(bind == 0 && jind == 0)
		dist = 0;
	int& ans = dp[bind][jind];
	if(ans > -1)
		return ans;
	ans = (int)10e19;
	if(jind+1 < j.size())
	{
		ans = min(ans, dist+solve(bind, jind+1));
	}
	if(bind+1 < b.size())
	{
		ans = min(ans, dist+solve(bind+1, jind));
	}
	if(jind+1 < j.size() && bind+1 < b.size())
	{
		ans = min(ans, dist+solve(bind+1, jind+1));
	}
	return ans;
}

#undef int
int main()
{
#define int long long
	freopen("radio.in", "r", stdin);
	freopen("radio.out", "w", stdout);
	cin >> N >> M;
	int bx, by, jx, jy;
	cin >> jx >> jy >> bx >> by;
	b.push_back(make_pair(bx, by));
	j.push_back(make_pair(jx, jy));
	for(int i = 0; i < N; i++)
	{
		char c;
		cin >> c;
		move(jx, jy, c);
		// cout << jx << " " << jy << endl;
		j.push_back(make_pair(jx, jy));
	}
	for(int i = 0; i < M; i++)
	{
		char c;
		cin >> c;
		move(bx, by, c);
		b.push_back(make_pair(bx, by));
	}
	for(int i = 0; i < 1005; i++)
	{
		for(int j = 0; j < 1005; j++)
		{
			dp[i][j] = -1;
		}
	}
	cout << solve(0, 0) << endl;	
}
