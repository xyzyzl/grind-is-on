#include <bits/stdc++.h>

#define int long long
#define ll long long
#define MAXN 50005

#define key first
#define val second 

#define add(k) pow(-1, k)

using namespace std;

int N;
vector<int> arr[MAXN];

struct container_hash
{
	int operator()(const vector<int> &V) const
	{
		int hash=0;
		for(int i=0;i<V.size();i++)
		{
			hash+=V[i];
		}
		return hash;
	}
};

unordered_map<vector<int>, int, container_hash > mp;
const int pie[5] = {1, -1, 1, -1, 1};


vector<int> subsets(vector<int> v, int mask)
{
	vector<int> st;
	for(int i = 0; i < 5; i++)
	{
		if((1 << i) & mask)
			st.push_back(v[i]);
	}
	return st;
}

#undef int
int main()
{
#define int long long
	freopen("cowpatibility.in", "r", stdin);
	freopen("cowpatibility.out", "w", stdout);
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			int aiya;
			cin >> aiya;
			arr[i].push_back(aiya);
		}
		sort(arr[i].begin(), arr[i].end());
		for(int j = 1; j < 32; j++)
			mp[subsets(arr[i], j)]++;
	}
	ll ans = N*(N-1)/2;
	for(auto &entry : mp) // foreach key do pie on # of overlaps
	{
		ans -= pie[entry.key.size() - 1] * (entry.val) * (entry.val-1) / 2;
	}
	cout << ans << endl;
}
