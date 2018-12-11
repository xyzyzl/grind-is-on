// not from online judge that other questions are from; actually IOI 2010 D1/1

#include <iostream>

using namespace std;
void solve()
{
	int arr[4] = {0, 6, 10, 6};
	int z;
	while(z=Theory(arr[1], arr[2], arr[3]) != 0)
	{
		arr[z]--;
	}
	cout << arr[1] << arr[2] << arr[3] << endl;
}