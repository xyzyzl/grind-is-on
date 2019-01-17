#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int n, m, restrict[MAXN], deg[MAXN];
bool freend[MAXN], goodnd[MAXN];
// friend was a keyword :(
vector<int> amigos[MAXN], xfirst[MAXN], yfirst[MAXN];
void dfs(int nd, int par)
{
	if(yfirst[nd].size() > 0)
		return;
	goodnd[nd] = true;
	for(int i : amigos[nd])
	{
		if(i != par)
			dfs(i, nd);
	}
}
int main()
{
	cout << "YO" << endl;
	// ios_base::sync_with_stdio(false);
	// cin.tie();
	ifstream fin("gathering.in");
	ofstream fout("gathering.out");
	fin >> n >> m;
	for(int i = 0; i < n-1; i++)
	{
		int x, y;
		fin >> x >> y;
		x--; y--;
		amigos[x].push_back(y);
		amigos[y].push_back(x);
		deg[x]++; deg[y]++;
	}
	for(int i = 0; i < m; i++)
	{
		int x, y;
		fin >> x >> y;
		x--; y--;
		xfirst[y].push_back(x);
		yfirst[x].push_back(y);
		restrict[y]++;
	}
	vector<int> free; // no restriction as to when to leave
	for(int i = 0; i < n; i++)
	{
		if(deg[i] <= 1 && restrict[i] == 0)
		{
			free.push_back(i);
			freend[i] = true;
		}
	}
	for(int i = 0; i < n-1; i++)
	{
		cout << i << endl;
		if(i == free.size())
		{
			for(int j = 0; j < n; j++)
				fout << 0 << endl;
			return 0;
		}
		int boi = free[i];
		// free node exits, alert all friends :( good bye
		for(int j = 0; j < amigos[boi].size(); j++)
		{
			int e = amigos[boi][j];
			deg[e]--;
			if(deg[e] <= 1 && restrict[e] == 0 && !freend[e])
			{
				free.push_back(e);
				freend[e] = true;
			}
		}
		for(int j = 0; j < yfirst[boi].size(); j++)
		{
			int e = yfirst[boi][j];
			restrict[e]--;
			if(deg[e] <= 1 && restrict[e] == 0 && !freend[e])
			{
				free.push_back(e);
				freend[e] = true;
			}
		}
	}
	cout << "gijoeshow" << endl;
	int rt = free[n-1];
	dfs(rt, -1); // gets all the possible end values
	for(int i = 0; i < n; i++)
		fout << (goodnd[i] ? 1 : 0) << endl;
	fout.flush();
}
