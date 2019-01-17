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

//  cookiemonster
#define MAXN 2004

using namespace std;

typedef long long ll;
typedef pair<double, int> pii;
#define x first
#define y second

int N, M, A, B;
double V;
vector<pii> adj_lst[MAXN];
double dist[MAXN];

long long ford() {
	for (int i = 0; i < N; i++) {
		dist[i] = LLONG_MAX;
	}
	dist[A] = V;
	for (int cnt = 1; cnt < N; cnt++) {
		for (int i = 0; i < N; i++) {
			for (pii j : adj_lst[i]) {
				if (dist[i] != LLONG_MAX && dist[i] * j.x < dist[j.y]) {
					dist[j.y] = dist[i] * j.x;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (pii j : adj_lst[i]) {
			if (dist[i] != LLONG_MAX && dist[i] * j.x < dist[j.y]) {
				return 0;
			}
		}
	}
	return floor(dist[B]);
}

int main() {
	cin >> N >> M >> V >> A >> B;
	A--; B--;
	for (int i = 0; i < M; i++) {
		int a, b;
		double r;
		cin >> a >> b >> r;
		a--; b--;

		adj_lst[a].push_back(make_pair(r, b));
	}
	cout << ford() << endl;
	return 0;
}
