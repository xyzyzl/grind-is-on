#include <iostream>

using namespace std;

int T;
int main()
{
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int l, w, h;
		cin >> l >> w >> h;
		cout << "Case " << i+1 << ": ";
		if(l <= 20 && w <= 20 && h <= 20)
			cout << "good" << endl;
		else
			cout << "bad" << endl;
	}
}