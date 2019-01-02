#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll M, N, L, H, B, ct, cct;
const int primes[6] = {2, 3, 5, 7, 11, 13};
const int pie[7] = {-1, 1, -1, 1, -1, 1, -1};
vector<int> divs[100001];

ll do_pie(ll k, ll I, int K, int lo, int hi)
{
	ll prod = 1;
	int num = 0;
	ll cnt = 0;
	for(int i = 0; i < K; i++)
	{
		if((1 << i) & k)
		{
			prod *= divs[I][i];
			num++;
		}
	}
	ll HI = hi / prod;
	ll LO = (lo + prod) / prod;
	cnt = (pie[num] * (HI-LO+1) * (M+1) - prod * (HI*(HI+1)) * (LO*(LO-1)/2));
	return cnt;
}

int main()
{
	cin >> M >> N >> L >> H >> B;
	for(int i = 2; i <= max(M, N); i++)
	{
		for(int j = 0; j < 6; j++)
		{
			if(i % primes[j] == 0)
				divs[i].push_back(primes[j]);
		}
	}
	ll HH = min(N, H);
	ll lo, hi;
	for(ll i = 1; i <= HH; i++)
	{
		cct = 0;
		lo = (ll)ceil(sqrt(max(1ll, L*L-i*i)));
		hi = (ll)sqrt(max(0ll, H*H-i*i));
		if(lo > hi || lo > M)
			continue;
		// you can iterate through all subsets of this
		int K = divs[i].size();
		for(int j = 1; j < (1 << K); j++)
		{
			cct += do_pie(j, i, K, lo, hi);
			cct %= b;
		}
		ct += (N-i-1) * cct;
		ct %= B;
		ct = ct * 2;
		ct %= B;
	}
	int big_num = (N+1)*(M+1) % B;
	int tot = big_num*(big_num-1)/2 % B;
	cout << (tot-2*ct+B)%B << endl;
}
