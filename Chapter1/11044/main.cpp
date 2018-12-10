#include <iostream>

using namespace std;

int T, M, N;

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N;
		cout << (M / 3) * (N / 3) << endl;
	}
}