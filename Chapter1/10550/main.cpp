#include <iostream>
#include <cmath>

using namespace std;

int mrdue(int due, int hoang) {
	if(hoang >= due)
		return 9*(due+(40-hoang));
	else
		return 9*(due-hoang);
}

int main() {
	while(true) {
		int due, hoang, is, godly;
		cin >> due >> hoang >> is >> godly;
		if(due+hoang+is+godly == 0)
			break;
		cout << (1080+mrdue(due, hoang)+mrdue(is, hoang)+mrdue(is, godly)) << endl;
	}
}