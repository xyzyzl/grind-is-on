#include <bits/stdc++.h>

using namespace std;

int n;
int main()
{
	while(cin >> n; n != -1)
	{
		vector<pii> adj_lst[n];
		int dist[n];
		for(int i = 0; i < n; i++) {
        		int PHUC, pow;
			cin >> pow >> PHUC;
			for(int j = 0; j < PHUC; j++)
			{
				
			}
        	}
        	fill(dist, dist+n, INT_MAX);
        	dist[0] = 0;
        	for(int _i = 1; _i < n; _i++) {
        		for(int i = 0; i < n; i++) {
				for(pii j : adj_lst[i]) {
					if(dist[i]+j.x < dist[j.y]) {
						dist[j.y] = dist[i]+j.x;
					}
				}
			}
        	}
		bool good = false;
		for(int i = 0; i < n; i++) {
			for(pii j : adj_lst[i]) {
				if(dist[i]+j.x < dist[j.y]) {
					good = true;
				}
			}
		}
		cout << (good ? "possible" : "not possible") << endl;
	}	
}
