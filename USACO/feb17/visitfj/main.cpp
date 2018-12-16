#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int> > pii;
#define x first
#define y second

int dx[16] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, -1, 1, 0, 0};
int dy[16] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};

int N, T;
int graph[105][105];
int dist[105][105];
priority_queue<pii, vector<pii>, greater<pii> > bfs;
int main()
{
	freopen("visitfj.in", "r", stdin);
	freopen("visitfj.out", "w", stdout);
	cin >> N >> T;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
			dist[i][j] = 1000000000;
		}
	}
	bfs.push(make_pair(0, make_pair(0, 0)));
	dist[0][0] = 0;
	int ans = 1000000000;
	while(!bfs.empty())
	{
		int d = bfs.top().x;
		int i = bfs.top().y.x;
		int j = bfs.top().y.y;
		bfs.pop();
		if(d != dist[i][j])
		{
			continue;
		}

		int _d = abs(N-1-i) + abs(N-1-j);
		// cout << _d << endl;
		if(_d <= 2)
		{
			ans = min(ans, d + _d * T);
		}
		for(int k = 0; k < 16; k++)
		{
			int ni = i + dx[k];
			int nj = j + dy[k];
			if(ni < 0 || ni >= N || nj < 0 || nj >= N || dist[ni][nj] < d + graph[ni][nj] + 3*T)
				continue;
			dist[ni][nj] = d + graph[ni][nj] + 3*T;
			bfs.push(make_pair(dist[ni][nj], make_pair(ni, nj)));
		}
	}
	cout << ans << endl;
}
