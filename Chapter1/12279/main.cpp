#include <iostream>

using namespace std;
int main()
{
	int N;
	int cs = 0;
	while(cin >> N, N != 0)
	{
		int ct = 0;
		for(int i = 0; i < N; i++)
		{
			int j;
			cin >> j;
			if(j != 0)
				ct++;
			else
				ct--;
		}
		cout << "Case " << ++cs << ": " << ct << endl;
	}
}