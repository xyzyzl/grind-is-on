#include <iostream>
#include <cmath>

using namespace std;

int N;
int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		int j = ((k*567)/9+7492)*235/47-498;
		j = abs(j);
		cout << (j / 10) % 10 << endl;
	}
}