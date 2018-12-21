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
		}

		// cout << Spos << endl;

		for (int i = 0; i <= N; i++)
		{
			for (int j = 0; j <= N; j++)
			{
				r[i][j] = INF;
				l[i][j] = INF;
			}
		}

		for (int i = Spos; i >= 0; i--)
		{
			for (int j = Spos; j <= N; j++)
			{
				if (i == Spos && j == Spos)
				{
					r[i][j] = 0;
					l[i][j] = 0;
				} else
				{
					r[i][j] = min((N + 1 - (j - i)) * (past[j] - past[j - 1]) + r[i][j - 1],
								  (N + 1 - (j - i)) * (past[j] - past[i]) + l[i][j - 1]);
					l[i][j] = min((N + 1 - (j - i)) * (past[i + 1] - past[i]) + l[i + 1][j],
								  (N + 1 - (j - i)) * (past[j] - past[i]) + r[i + 1][j]);
				}
			}
		}

		// cout << "howlett" << endl;
		cout << min(l[0][N], r[0][N]) << endl;

	} else
	{
		sort(past, past + N);

		for (int i = 0; i < N; i++)
		{
			if (past[i] == S)
			{
				Spos = i;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				r[i][j] = INF;
				l[i][j] = INF;
			}
		}

		for (int i = Spos; i >= 0; i--)
		{
			for (int j = Spos; j < N; j++)
			{
				if (i == Spos && j == Spos)
				{
					r[i][j] = 0;
					l[i][j] = 0;
				} else
				{
					r[i][j] = min((N - (j - i)) * (past[j] - past[j - 1]) + r[i][j - 1],
								  (N - (j - i)) * (past[j] - past[i]) + l[i][j - 1]);
					l[i][j] = min((N - (j - i)) * (past[i + 1] - past[i]) + l[i + 1][j],
								  (N - (j - i)) * (past[j] - past[i]) + r[i][j - 1]);
				}
			}
		}

		cout << min(l[0][N - 1], r[0][N - 1]) << endl;
	}


}
