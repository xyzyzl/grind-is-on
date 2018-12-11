#include <iostream>
#include <string>

using namespace std;

int main()
{
	int Q;
	cin >> Q;
	int qool = 0;
	for(int i = 0; i < Q; i++)
	{
		string s;
		cin >> s;
		if(s == "donate")
		{
			int qooler;
			cin >> qooler;
			qool += qooler;
		} else
			cout << qool << endl;
	}
}