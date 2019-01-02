#include <bits/stdc++.h>

#define MAXN 100005
#define int long long

using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

int n, m, k, dist1[MAXN], dist2[MAXN], indeg[MAXN];
pii delet[MAXN];
bool tl[MAXN];
vector<pii> adj_lst[MAXN];
vector<int> alex_gu_got_bars;

void dijkstra1()
{
	fill(dist1, dist1 + n, (long long)10e18);
	dist1[0] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(make_pair(0, 0));
	while (!pq.empty())
	{
		pii front = pq.top();
		pq.pop();
		int d = front.f, u = front.s;
		if (d > dist1[u])
			continue;
		for (int i = 0; i < adj_lst[u].size(); i++)
		{
			pii v = adj_lst[u][i];
			if (dist1[u] + v.s < dist1[v.f])
			{
				dist1[v.f] = dist1[u] + v.s;
				pq.push(make_pair(dist1[v.f], v.f));
			}
		}
	}
}

#undef int
int main()
#define int long long
{
	cin >> n >> m >> k;
	fill(dist2, dist2 + n, (long long)10e18);
	for(int i = 0; i < m; i++)
	{
		int u, v, x;
		cin >> u >> v >> x;
		u--; v--;
		adj_lst[u].push_back(make_pair(v, x));
		adj_lst[v].push_back(make_pair(u, x));
	}
	/*
	for(int i = 0; i < n; i++)
		cout << dist1[i] << endl;
	*/
	for(int i = 0; i < k; i++)
	{
		int s, y;
		cin >> s >> y;
		s--;
		adj_lst[s].push_back(make_pair(0, y));
		adj_lst[0].push_back(make_pair(s, y));
		delet[i] = make_pair(s, y);
	}
	dijkstra1();
	for(int i = 0; i < n; i++)
	{
		for(pii p : adj_lst[i])
			if(dist1[i] + p.s == dist1[p.f])
				indeg[p.f]++;
	}
	int ct = 0;
	for(pii tr : delet)
	{
		if(indeg[tr.f] > 1 && dist1[tr.f] == tr.s)
		{
			ct++;
			indeg[tr.f]--;
		} else if(dist1[tr.f] != tr.s)
			ct++;
	}
	cout << ct << endl;
}
