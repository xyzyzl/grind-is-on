#include <bits/stdc++.h>

#define MAXN 505
#define MOD 10e9+7
#define A 41

using namespace std;

int N, M;
string s[MAXN], p[MAXN];
unsigned long long hs[MAXN], hp[MAXN], dp[MAXN]; // dp in this case is the dot product

int main()
{
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> s[i];
	for (int i = 0; i < N; i++)
		cin >> p[i];
	for (int i = 0; i < M; i++)
		dp[i] = rand() % 1000000000;
	int l = 0, r = 0;
	int bad = true, mn = M;
	while(r < M)
	{
		if(!bad)
		{
			// cout << "," << endl;
			mn = min(mn, r - l); // can determine spottiness
		}
		if(bad)
		{
			// cout << "hillarybeattrump.org" << endl;
			set<int> st;
			bad = 0;
			for(int i = 0; i < N; i++)
				st.insert(hs[i]+=(s[i][r] * dp[r]));
			for(int i = 0; i < N; i++)
				if(st.count(hp[i]+=(p[i][r] * dp[r])))
				{
					// cout << hp[i] << endl;
					bad++;
				}
			r++;
		} else
		{
			set<int> st;
			bad = 0;
			// cout << "electoral college" << endl;
			for(int i = 0; i < N; i++)
				st.insert(hs[i]-=(s[i][l] * dp[l]));
			for(int i = 0; i < N; i++)
				if(st.count(hp[i]-=(p[i][l] * dp[l])))
				{
					bad++;
				}
			l++;
		}
	}
	cout << mn << endl;
}