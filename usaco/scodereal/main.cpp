#include <bits/stdc++.h>

#define MOD 2014

using namespace std;

string s;
map<string, int> dp; // each string
int my_very_good_naming_conventions(string str)
{
	if (dp.find(str) != dp.end())
		return dp[str];
	int ans = 1, len = str.length();
	for (int i = 1; i * 2 < len; i++)
	{
		if (str.substr(0, i) == str.substr(len - i, i))
			ans += my_very_good_naming_conventions(str.substr(i, len - i));
		if (str.substr(0, i) == str.substr(i, i))
			ans += my_very_good_naming_conventions(str.substr(i, len - i));
		if (str.substr(0, i) == str.substr(len - i, i))
			ans += my_very_good_naming_conventions(str.substr(0, len - i));
		if (str.substr(len - i * 2, i) == str.substr(len - i, i))
			ans += my_very_good_naming_conventions(str.substr(0, len - i));
	}
	ans %= MOD;
	dp[str] = ans;
	return ans;
}

int main()
{
	freopen("scode.in", "r", stdin);
	freopen("scode.out", "w", stdout);
	cin >> s;
	cout << ((my_very_good_naming_conventions(s) + MOD - 1) % MOD) << endl;
}