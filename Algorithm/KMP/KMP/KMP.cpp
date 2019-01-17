#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>

#include <array>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <list>

#include <cstdio>
#include <climits>
#include <cmath>
#include <cassert>

using namespace std;

#define MAXN 15

#define mp make_pair
#define pb push_back
#define	ll long long
#define INF (1e9*1)+5
#define LL_INF (1e18*1)+5
#define bitinc(s) (s&-s)

typedef pair<int, int> pii;
#define f first
#define s second

void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix 
	// values for pattern 
	int lps[M];

	// Preprocess the pattern (calculate lps[] array) 
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			printf("Found pattern at index %d ", i - j);
			j = lps[j - 1];
		}

		else if (i < N && pat[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

void computeLPSArray(char* pat, int M, int* lps)
	int len = 0;

	lps[0] = 0; 
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0) {
				len = lps[len - 1];

			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

// Driver program to test above function 
int main()
{
	char txt[] = "ABABDABACDABABCABAB";
	char pat[] = "ABABCABAB";
	KMPSearch(pat, txt);
	return 0;
}