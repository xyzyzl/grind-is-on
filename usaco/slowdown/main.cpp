#include <bits/stdc++.h>

using namespace std;

int N, T, D;
vector<int> tem, dst;
double cur_t = 0.0, cur_d = 0.0;
int cur_m = 1; // time, dist, multiplier
int tind, dind, tot;
int main()
{
	freopen("slowdown.in", "r", stdin);
	freopen("slowdown.out", "w", stdout);
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		char c;
		int x;
		cin >> c >> x;
		if(c == 'T')
			tem.push_back(x);
		else
			dst.push_back(x);
	}
	dst.push_back(1000); // need to calculate dist to the end
	T = tem.size();
	D = dst.size();
	// cout << T << D << endl;
	sort(tem.begin(), tem.end());
	sort(dst.begin(), dst.end());
	while(tind < T || dind < D)
	{
		bool tem_small = false;
		if(dind >= D)
			tem_small = true;
		else if(dind < D && tind < T && tem[tind] < (cur_t+(dst[dind]-cur_d)*cur_m))
			tem_small = true;
		if(tem_small)
		{
			double pre_t = cur_t;
			cur_t = tem[tind];
			cur_d += (tem[tind]-pre_t) / (double)cur_m;
			tind++;
		} else
		{
			double pre_d = cur_d;
			cur_d = dst[dind];
			cur_t += (dst[dind]-pre_d) * (double)cur_m;
			dind++;
		}
		cur_m++;
	}
	int ans = (int)cur_t;
	double rnd = cur_t - ans;
	// cout << cur_t << endl;
	if(rnd < 0.5)
		cout << ans << endl;
	else
		cout << ans+1 << endl;
}
