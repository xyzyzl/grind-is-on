#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj_lst[MAXN], adj_lst2[MAXN];
int tcnt = 0;
bool fool[MAXN], vis[MAXN];

deque<int> t0po;
int topo[MAXN];

void dfs(int x) {
	tcnt++;
	fool[x] = true;
	for(int child : adj_lst[x]) {
		if(fool[child])
			continue;
		dfs(child);
	}
	t0po.push_front(x);
}
int sze = 0;
void dfs2(int x) {
	sze++;
	vis[x] = true;
	for(int child : adj_lst2[x]) {
		if(vis[child])
			continue;
		dfs2(child);
	}
}
