#include <bits/stdc++.h>

#define MAXN 50005

using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

int N, M, K;
map<pii, int> adj_lst;
vector<int> edges[MAXN];
int dist[2][MAXN];

void dijkstra(int N, int aiya)
{
	N++;
	fill(dist[aiya], dist[aiya] + MAXN, 1000000000);
	dist[aiya][N - 1] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(make_pair(0, N - 1));
	while (!pq.empty())
	{
		pii front = pq.top();
		pq.pop();
		int d = front.f, u = front.s;
		if (d > dist[aiya][u])
			continue;
		for(int i = 0; i < edges[u].size(); i++)
		{
			int v = edges[u][i];
			int dst = adj_lst[make_pair(u, v)];
			if(dist[aiya][u] + dst < dist[aiya][v])
			{
				dist[aiya][v] = dist[aiya][u] + dst;
				pq.push(make_pair(dist[aiya][v], v));
			}
		}
	}
}

int main()
{
	freopen("dining.in", "r", stdin);
	freopen("dining.out", "w", stdout);
	cin >> N >> M >> K;
	for(int i = 0; i < M; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
		adj_lst[make_pair(a, b)] = w;
		adj_lst[make_pair(b, a)] = w;
	}
	dijkstra(N-1, 0);
	for(int i = 0; i < K; i++)
	{
		int a, v;
		cin >> a >> v;
		a--;
		edges[N].push_back(a); // you need to offset by the yumminess of the bale
		adj_lst[make_pair(N, a)] = dist[0][a] - v; // does the offset by adding a new node
	}
	dijkstra(N, 1);
	for(int i = 0; i < N-1; i++)
	{
		// oops it was calculating one too little :(
		// cout << dist[0][i] << " " << dist[1][i] << endl;
		cout << (dist[1][i] <= dist[0][i]) << endl;;
	}
}
