#include <bits/stdc++.h>

#define MAXN 50005

using namespace std;

int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};

int adx[4] = {-1, 0, 0, 1};
int ady[4] = {0, -1, 1, 0};

typedef pair<int, int> pii;
#define f first
#define s second

int N, per;
set<pii> vis;
set<pii> hay;
void dfs(pii p)
{
	if(hay.count(p))
	{
		per++;
		return;
	}
	if(vis.count(p))
		return;
	vis.insert(p);
	bool gumwaa = true;
	for(int i = 0; i < 8; i++)
	{
		pii np = make_pair(p.f + dx[i], p.s + dy[i]);
		if(hay.count(np))
		{
			gumwaa = false;
		}
	}
	if(gumwaa)
		return;
	for(int i = 0; i < 4; i++)
		dfs(make_pair(p.f+adx[i], p.s+ady[i]));
}

int main()
{
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		hay.insert(make_pair(a, b));
	}
	pii st = make_pair(hay.begin()->f-1, hay.begin()->s-1);
	dfs(st);
	cout << per << endl;
}