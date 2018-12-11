// another IOI problem (didn't do this is clion)
#include <iostream>

using namespace std;

int arr[26][2];
void solve()
{
	for(int i = 1; i <= 50; i++)
	{
		int ind = faceup(i) - 64;
		if(arr[ind][0])
			arr[ind][1] = i;
		else
			arr[ind][0] = i;
	}
	for(int i = 1; i <= 25; i==)
	{
		faceup(arr[i][0]);
		faceup(arr[i][1]);
	}
}
