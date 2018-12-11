#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	int ct=0;
	while(cin >> s, s != "*")
	{
		cout << "Case " << ++ct << ": ";
		if(s == "Hajj")
			cout << "Hajj-e-Akbar" << endl;
		else
			cout << "Hajj-e-Asghar" << endl;
	}
}