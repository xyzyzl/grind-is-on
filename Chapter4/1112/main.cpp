#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

int n, e, s, m;
int dist1[105];
vector<pii> adj_lst[105];
void dijkstra1()
{
	fill(dist1, dist1 + n, 1000000000);
	dist1[e - 1] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(make_pair(0, e - 1));
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



void run()
{
	cin >> n >> e >> s >> m;
	for(int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		adj_lst[a].push_back(make_pair(b, w));
	}
	dijkstra1();
	int ct = 0;
	for(int i = 0; i < n; i++)
		if(dist1[i] <= s)
			ct++;
	cout << ct << endl;
}
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
		run();
}
