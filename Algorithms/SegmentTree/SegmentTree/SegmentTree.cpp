// SegmentTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class SegmentTree
{
private:
	vector<int> st, A;
	int n;
	int left(int p)
	{
		return (p << 1);
	}
	int right(int p)
	{
		return (p << 1) + 1;
	}

	void build(int p, int L, int R)
	{
		if (L == R)
			st[p] = L;
		else
		{
			build(left(p), L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] <= A[p2] ? p1 : p2);
		}
	}

	void upd(int p, int L, int R, int i, int val)
	{
		if (i < L || i > R)
			return;

		st[p] = st[p] + val;
		if (R != L)
		{
			upd(left(p), L, (L + R) / 2, i, val);
			upd(right(p), (L + R) / 2 + 1, R, i, val);
		}
	}

	int rmq(int p, int L, int R, int i, int j)
	{
		if (i > R || j < L)
			return -1;
		if (L >= i && R <= j)
			return st[p];

		int p1 = rmq(left(p), L, (L + R) / 2, i, j);
		int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

		if (p1 == -1)
			return p2;
		if (p2 == -1)
			return p1;
		return (A[p1] <= A[p2]) ? p1 : p2;
	}
public:
	SegmentTree(const vector<int> &_A)
	{
		A = _A;
		n = (int)A.size();
		st.assign(4 * n, 0);
		build(1, 0, n - 1);
	}
	int rmq(int i, int j)
	{
		return rmq(1, 0, n - 1, i, j);
	}
	void upd(vector<int> a, int i, int nw)
	{
		if (i < 0 || i >= n)
		{
			cout << "ur bad" << endl;
			return;
		}
		int val = nw - a[i];
		a[i] = nw;
		upd(0, 0, n - 1, i, val);
	}
};

int main()
{
	cout << "Hello World !" << endl; // testing visual studio functionality
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
