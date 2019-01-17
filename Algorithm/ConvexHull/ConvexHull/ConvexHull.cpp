#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

typedef pair<int, int> pii;
#define x first
#define y second

vector<pii> hull;

int n;
pii points[5005];

int orientation(pii a, pii b, pii c) {
	int ret = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
	if (ret == 0)
		return 0;
	return ret > 0 ? 1 : 2;
}

void convex_hull() {
	// There must be at least 3 points
	if (n < 3) return;

	int l = 0;
	for (int i = 1; i < n; i++)
		if (points[i].x < points[l].x)
			l = i;

	int p = l, q;
	do {
		hull.push_back(points[p]);

		q = (p + 1) % n;
		for (int i = 0; i < n; i++) {
			if (orientation(points[p], points[i], points[q]) == 2)
				q = i;
		}

		p = q;

	} while (p != l);
	double sum = 0;
	for (int i = 0; i < hull.size() - 1; i++) {
		double x1 = (double)hull[i].x;
		double y1 = (double)hull[i].y;
		double x2 = (double)hull[i + 1].x;
		double y2 = (double)hull[i + 1].y;
		sum += sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
		// cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
		// cout << (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) << endl;
	}
	sum += sqrt(((double)hull[0].x - (double)hull[hull.size() - 1].x)*((double)hull[0].x - (double)hull[hull.size() - 1].x) +
		((double)hull[0].y - (double)hull[hull.size() - 1].y)*((double)hull[0].y - (double)hull[hull.size() - 1].y));
	cout << setprecision(2) << fixed << sum << endl;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y;
	}
	convex_hull();
	return 0;
}
