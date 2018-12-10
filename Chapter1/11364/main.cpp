#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
vector<int> v;

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		v.clear();
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int j;
			cin >> j;
			v.push_back(j);
		}
		sort(v.begin(), v.end());
		cout << 2 * (*v.rbegin() - *v.begin()) << endl;
	}
}