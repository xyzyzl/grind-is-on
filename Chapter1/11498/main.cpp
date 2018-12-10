#include <iostream>

using namespace std;

int K;
int m, n;
int x, y;
int main() {
	cin >> K;
	while(K != 0) {
		if(K)
			cin >> m >> n;
		while(K--) {
			cin >> x >> y;
			if(x == m || y == n)
				cout << "divisa" << endl;
			else if(x < m && y > n)
				cout << "NO" << endl;
			else if(x < m && y < n)
				cout << "SO" << endl;
			else if(x > m && y > n)
				cout << "NE" << endl;
			else
				cout << "SE" << endl;
		}
		cin >> K;
	}
}