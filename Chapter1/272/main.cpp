/* sample input:
"I love DUE HOANG", said the person.
*/

#include <iostream>
#include <cstdio>

using namespace std;
int k = 0;

int main()
{
	while (!cin.eof())
	{
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '\"')
			{
				k++;
				k %= 2;
				if (k)
					cout << "``";
				else
					cout << "\'\'";
			} else
			{
				cout << s[i];
			}
		}
		cout << (char) getchar();
	}
}