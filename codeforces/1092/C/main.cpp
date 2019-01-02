#include <bits/stdc++.h>

#define MAXN 1010
#define INF 632632632

using namespace std;

typedef stack<int> sti;
typedef queue<int> qi;
typedef set<int> si;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
#define x first
#define y second

long long l[MAXN][MAXN], r[MAXN][MAXN];
int N, S, Spos;
int past[MAXN];

int main()
{
	freopen("cowrun.in", "r", stdin);
	freopen("cowrun.out", "w", stdout);
	cin >> N;
	S = 0;
	bool has_S = false;
	for (int i = 0; i < N; i++)
	{
		cin >> past[i];
		if (past[i] == S)
			has_S = true;
	}

	if (!has_S)
	{
		past[N] = S;

		sort(past, past + N + 1);

		/**
		for(int i = 0; i < N+1; i++){
			cout << past[i] << endl;
		}
		**/

		for (int i = 0; i <= N; i++)
		{
			if (past[i] == S)
				Spos = i;
