#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

typedef pair<int, int> pii;
#define f first
#define s second

struct UnionFind
{
	vector<int> p, rank;

	UnionFind()
	{}

	UnionFind(int N)
	{
		rank.assign(N, 1);
		p.assign(N, 0);
		for(int i = 0; i < N; i++)
			p[i] = i;
	}
	int findSet(int i)
	{
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	int size(int i)
	{
		return rank[findSet(i)];
	}
	bool isSameSet(int i, int j)
	{
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j)
	{
		int x = findSet(i), y = findSet(j);
		rank[y] += rank[x];
		p[x] = y;
	}
} uf;

typedef pair<int, pii> edge;
vector<edge> e;
vector<edge> q;
vector<int> ans;

int N, Q;
int main()
{
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	cin >> N >> Q;
	uf = UnionFind(N);
	for(int i = 0; i < N - 1; i++)
	{
		int a, b, r;
		cin >> a >> b >> r;
		a--;
		b--;
		e.push_back(make_pair(r, make_pair(a, b)));
	}
	sort(e.begin(), e.end());
	reverse(e.begin(), e.end()); // decreasing order of relevance
	for(int i = 0; i < Q; i++)
	{
		int a, r;
		cin >> r >> a;
		a--;
		q.push_back(make_pair(r, make_pair(a, i)));
	}
	sort(q.begin(), q.end());
	int ind = 0;
	ans.assign(Q, 0);
	reverse(q.begin(), q.end()); // decreasing order of relevance, this allows us to only add edges
	for(edge que : q)
	{
		while(ind < e.size() && e[ind].f >= que.f)
		{
			// cout << "yooyyooyyooy" << endl;
			uf.unionSet(e[ind].s.f, e[ind].s.s);
			ind++;
		}
		/*
		for(int i = 0; i < N; i++)
		{
			cout << uf.size(i) << endl;
		}
		*/

		ans[que.s.s] = uf.size(que.s.f);
	}
	for(int hi : ans)
	{
		cout << hi-1 << endl; // start node
	}
}
