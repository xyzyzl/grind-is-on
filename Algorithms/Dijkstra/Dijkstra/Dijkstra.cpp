// Dijkstra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

#define MAXN 50005
// whatever MAXN is supposed to be

using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

int dist[2][MAXN];
map<pii, int> adj_lst;
vector<int> edges[MAXN];

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
		for (int i = 0; i < edges[u].size(); i++)
		{
			int v = edges[u][i];
			int dst = adj_lst[make_pair(u, v)];
			if (dist[aiya][u] + dst < dist[aiya][v])
			{
				dist[aiya][v] = dist[aiya][u] + dst;
				pq.push(make_pair(dist[aiya][v], v));
			}
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
