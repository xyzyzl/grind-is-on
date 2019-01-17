#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>

#include <array>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <list>

#include <cstdio>
#include <climits>
#include <cmath>
#include <cassert>

#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;

int N, E;
vector<pii> adj_lst[50100];
bool vis[50100];
int wt[50100];

int prim() {

	fill(vis, vis + N, false);
	fill(wt, wt + N, 632632632);

	priority_queue<pii> pq;
	pq.push(make_pair(0, 0));

	while (!pq.empty()) {
		pii tp = pq.top();
		pq.pop();
		if (vis[tp.y])
			continue;
		vis[tp.y] = true;

		for (pii gu : adj_lst[tp.y]) {
			int w = gu.first;
			int ind = gu.second;
			if (!vis[ind] && w < wt[ind]) {
				wt[ind] = w;
				pq.push(make_pair(-w, ind));
			}
		}
	}

	int xiangjiao = 0;
	for (int i = 1; i < N; i++) {
		// cout << wt[i] << endl;
		xiangjiao += wt[i];
		// cout << "Mr. G" << endl;
		// cout << xiangjiao << endl;
		// cout << endl;
	}
	// cout << xiangjiao << endl;
	return xiangjiao;

}

int main() {

	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;

		adj_lst[a].push_back(make_pair(w, b));
		adj_lst[b].push_back(make_pair(w, a));
	}

	cout << prim() << endl;

}
