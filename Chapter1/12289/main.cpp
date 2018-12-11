#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if(s.size() == 3)
		{
			if((s[0] == 'o' && s[1] == 'n') || (s[1] == 'n' && s[2] == 'e')
				|| (s[0] == 'o' && s[2] == 'e'))
				cout << 1 << endl;
			else
				cout << 2 << endl;
		}
		else if(s.size() == 5)
			cout << 3 << endl;
	}
}