#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define SZE 262144

#define mp make_pair
#define pb push_back
#define    ll long long
#define INF (1e9*1)+5
#define LL_INF (1e18*1)+5
#define bitinc(s) (s&-s)

typedef pair<int, int> pii;
#define f first
#define s second

int N;
ll k;
int arr[MAXN], tree[SZE];

bool comp(pii a, pii b)
{
	if(a.f == b.f)
		return a.s > b.s;
	return a.f < b.f;
}

void build(int pos, int lo, int hi, int ind, int val)
{
	if (ind < lo || ind > hi)
	{
		return;
	}
	if (lo == hi) // leaf node
	{
		tree[pos] = val;
		return;
	}
	int mid = (lo + hi) / 2;
	build(pos * 2 + 1, lo, mid, ind, val); // left node
	build(pos * 2 + 2, mid + 1, hi, ind, val); // right node

	tree[pos] = max(tree[pos * 2 + 1], tree[pos * 2 + 2]);
}

int mquery(int pos, int lo, int hi, int st, int end)
{
	if (lo >= st && hi <= end)
		return tree[pos];
	if (st > hi || end < lo)
		return 0;
	int mid = (lo + hi) / 2;
	return max(mquery(2 * pos + 1, lo, mid, st, end),
			mquery(2 * pos + 2, mid + 1, hi, st, end));
}

int lis()
{
	pii p[N];
	for(int i = 0; i < N; i++)
	{
		p[i] = mp(arr[i], i);
	}
	sort(p, p+N, comp);
}

int main()
{
	cin >> N >> k;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

}