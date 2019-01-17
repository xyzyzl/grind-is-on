#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <complex> // allows for fft

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

using namespace std;

#define MAXN 2505

#define mp make_pair
#define pb push_back
#define	ll long long
#define INF (1e9*1)+5
#define LL_INF (1e18*1)+5
#define bitinc(s) (s&-s)

typedef pair<int, int> pii;
#define f first
#define s second

int N, E;
int adj_mat[MAXN][MAXN];
int dir_nodes[MAXN];
int w[MAXN];
bool vis[MAXN];

int prim() 
{

	for (int i = 0; i < N; i++) 
	{
		w[i] = 100001;
		vis[i] = false;
	}

	w[0] = 0; // first vertex, dist. 0
	dir_nodes[0] = -1; // this is the source node

	// foreach vertex
	for (int vert = 1; vert < N; vert++) 
	{

		int min = 100001;
		int ind;

		for (int i = 0; i < N; i++) 
		{
			if (!vis[i] && w[i] < min) 
			{
				min = w[i];
				ind = i;
			}
		}

		// ind is now the best ind

		vis[ind] = true;

		for (int i = 0; i < N; i++) 
		{

			if (adj_mat[ind][i] > 0 && !vis[i] && adj_mat[ind][i] < w[i]) 
			{
				dir_nodes[i] = ind;
				w[i] = adj_mat[ind][i];
			}

		}

	}
	int sum = 0;
	for (int i = 1; i < N; i++) 
	{
		sum += w[i];
	}

	return sum;

}

int main() 
{

	cin >> N >> E;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			adj_mat[i][j] = 6326326969;

	for (int i = 0; i < N; i++)
		adj_mat[i][i] = 0;

	for (int i = 0; i < E; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;

		adj_mat[a][b] = w;
		adj_mat[b][a] = w;
	}

	cout << prim() << "\n";

}