#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

int n, m, k;
vector<pii> adj_lst[50005];

int dist1[50005];
bool good[50005];

void dijkstra1()
{
	fill(dist1, dist1 + n, 1000000000);
	dist1[n - 1] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(make_pair(0, n - 1));
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

// does this bale
int* dijkstra2(int bale)
{
	int* dist;
	dist = new int[n];
	fill(dist, dist + n, 1000000000);
	dist[bale] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(make_pair(0, bale));
	while (!pq.empty())
	{
		pii front = pq.top();
		pq.pop();
		int d = front.f, u = front.s;
		if (d > dist[u])
			continue;
		for (int i = 0; i < adj_lst[u].size(); i++)
		{
			pii v = adj_lst[u][i];
			if (dist[u] + v.s < dist[v.f])
			{
				dist[v.f] = dist[u] + v.s;
				pq.push(make_pair(dist[v.f], v.f));
			}
		}
	}
	return dist;
}


int main()
{
	cin >> n >> m >> k;
	// cout << n << m << k;
	for (int i = 0; i < m; i++)
	{
		int a, b, g;
		cin >> a >> b >> g;
		a--;
		b--;
		adj_lst[a].push_back(make_pair(b, g));
		adj_lst[b].push_back(make_pair(a, g));
	}
	dijkstra1();
	int* hello;
	hello = new int[n];
	for(int i = 0; i < k; i++)
	{
		int a, v;
		cin >> a >> v;
		hello = dijkstra2(a-1);
		a--;
		for(int i = 0; i < n-1; i++)
		{
			if(hello[i]+dist1[a]-v <= dist1[n])
				good[i] = true;
		}
	}
	for(int i = 0; i < n-1; i++)
		cout << good[i] << endl;
}
