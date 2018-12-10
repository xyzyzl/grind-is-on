// WA

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> adj_lst[26];
int ctt[30];
int vis[26]; // is it visited, if so when
void dfs(int nd, int ct)
{
	vis[nd] = ct;
	for(int i : adj_lst[nd])
	{
		if(vis[i] == 0)
			dfs(i, ct);
	}
}
int main()
{
	cin >> N;
	for(int cot = 0; cot < N; cot++)
	{
		for(int i = 0; i < 26; i++)
		{
			adj_lst[i].clear();
			vis[i] = 0;
		}
		for(int i = 0; i < 30; i++)
			ctt[i] = 0;
		vector<pair<int, int> > v;
		string s;
		cin >> s;
		while(s[0] != '*')
		{
			int a = s[1]-65;
			int b = s[3]-65;
			adj_lst[a].push_back(b);
			adj_lst[b].push_back(a);
			cin >> s;
		}
		cin >> s;
		int ct = 0;
		for(int i = 0; i < s.length(); i+=2)
		{
			int nd = s[i]-65;
			if(vis[nd] == 0)
			{
				// cout << s[i] << endl;
				dfs(nd, ++ct);
			}
		}
		for(int i = 0; i < 26; i++)
		{
			if(vis[i] != 0)
			{
				ctt[vis[i]]++;
				// cout << vis[i] << " " << (char)(i+65) << endl;
			}
		}
		int tree = 0, acorn = 0;
		for(int i = 0; i < 26; i++)
		{
			if(ctt[i] != 0)
			{
				if(ctt[i] > 1)
					tree++;
				else
					acorn++;
			}
		}
		cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s)." << endl;
	}
}