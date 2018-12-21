#include <bits/stdc++.h>

using namespace std;

typedef stack<int> sti;
typedef queue<int> qi;
typedef set<pair<int, int> > si;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;

typedef pair<pair<int, pii>, bool> state;

int N;
si s;

int vis;

vector<state> states;

int main(){

	freopen("painting.in", "r", stdin);
	freopen("painting.out", "w", stdout);

	cin >> N;

	for(int i = 0; i < N; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// first x coordinate interval of each rectangle, y coordinate interval, should we add?
		states.push_back(make_pair(make_pair(x1, make_pair(y1, y2)), true));
		states.push_back(make_pair(make_pair(x2, make_pair(y1, y2)), false));
	}

	sort(states.begin(), states.end());

	// process each condition
	// REMOVING THE RECTANGLE: if you add it and it is in another rectangle don't add anything to the count.
	// adding rectangles like normal really does nothing
	for(int i = 0; i < 2*N; i++){
		// cout << i << endl;
		if(states[i].second){
			// checks only work with something there
			if(!s.empty()){
				// first part is the current one
				// second part just needs to be big
				pii p = make_pair(states[i].first.second.first, 6326326969);
				auto lb = (s.lower_bound(p));
				lb--;
				pii plb = *lb;

				// cout << plb.first << " " << plb.second << " line50" << endl;

				if(plb.first < states[i].first.second.first && plb.second > states[i].first.second.second){
					// cout << "weird creature" << endl;
					// cout << i << " 110" << endl;
					continue;
				}
				// cout << i << " 111" << endl;
				s.insert(states[i].first.second);
				vis++;
			} else{
				// cout << states[i].first.second.first << endl;
				// cout << states[i].first.second.second << endl;
				// cout << i << " 10" << endl;
				s.insert(states[i].first.second);
				vis++;
			}
		} else{
			// cout << i << " 0" << endl;
			if(s.find(states[i].first.second) != s.end())
				s.erase(s.find(states[i].first.second));
		}

		// cout << "you're here" << endl;
	}

	cout << vis << endl;

}
