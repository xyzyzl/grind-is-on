#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define mult 100000ll

#define mp make_pair
#define pb push_back
#define	ll long long
#define INF (1e9*1)+5
#define LL_INF (1e18*1)+5
#define bitinc(s) (s&-s)

typedef pair<int, int> pii;
#define f first
#define s second
typedef vector<int> vi;
typedef vector<pii> vp;

int n;
ll f[MAXN];
int l[MAXN];
int r[MAXN];
int main()
{
	freopen("balance.in", "r", stdin);
	freopen("balance.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> f[i];
	}
	f[0] = f[n+1] = 0;
	vi hull;
	hull.pb(0);
	for(int x = 1; x <= n+1; x++)
	{
		while(hull.size() >= 2)
		{
			int i = hull[hull.size() - 2];
			int j = hull[hull.size() - 1];
			if((x-i)*f[j] < (j-i)*f[x] + (x-j)*(f[i]))
				hull.erase(hull.end()-1);
			else
				break;
		}
		hull.pb(x);
	}
	for(int i = 0; i < hull.size()-1; i++)
	{
		for(int j = hull[i]; j < hull[i+1]; j++)
		{
			l[j] = hull[i];
			r[j] = hull[i+1];
		}
		l[hull[i]]=r[hull[i]]=hull[i];
	}
	l[n+1] = r[n+1] = n+1;
	for(int i = 1; i <= n; i++)
	{
		if(l[i] == r[i]) // point on hull
			cout << mult*f[i] << endl;
		else
			cout << mult*((((ll)(r[i]-i))*((ll)f[l[i]]) + ((ll)(i - l[i]))*((ll)f[r[i]])))/((ll)(r[i]-l[i])) << endl;
	}
}
