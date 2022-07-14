#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long

const int LOGN = 32;
/*
https://leetcode.com/problems/longest-word-in-dictionary/
https://binarysearch.com/problems/Max-XOR-of-Two-Integers/


https://codeforces.com/problemset/problem/706/D
https://codeforces.com/problemset/problem/455/B
https://codeforces.com/problemset/problem/282/E
https://codeforces.com/contest/1625/problem/D
https://codeforces.com/contest/1625/problem/D
*/

void solve() {
	int q;
	cin >> q;

	vector<vector<pair<int, int>>> trie(1, vector<pair<int, int>>(2ll, {0, 0}));//{node,freq}

	int cur = 0;

	while (q--) {
		char op;
		cin >> op;
		if (op == '+') {
			int x;
			cin >> x;
			string s;

			for (int i = LOGN - 1; i >= 0; i--) {
				if (x & 1ll << i) {
					s.push_back('1');
				} else {
					s.push_back('0');
				}
			}
			int node = 0;
			for (auto c : s) {
				if (trie[node][c - '0'].first == 0) {
					trie.push_back(vector<pair<int, int>>(2ll, {0, 0}));
					trie[node][c - '0'].first = ++cur;
				}
				trie[node][c - '0'].second++;
				node = trie[node][c - '0'].first;
			}
		} else if (op == '-') {
			int x;
			cin >> x;
			string s;

			for (int i = LOGN - 1; i >= 0; i--) {
				if (x & 1ll << i) {
					s.push_back('1');
				} else {
					s.push_back('0');
				}
			}
			int node = 0;
			for (auto c : s) {
				if (trie[node][c - '0'].first == 0) {
					trie.push_back(vector<pair<int, int>>(2ll, {0, 0}));
					trie[node][c - '0'].first = ++cur;
				}
				trie[node][c - '0'].second--;
				node = trie[node][c - '0'].first;
			}
		} else {
			int x;
			cin >> x;
			string s;

			for (int i = LOGN - 1; i >= 0; i--) {
				if (x & 1ll << i) {
					s.push_back('1');
				} else {
					s.push_back('0');
				}
			}
			int node = 0;
			string mx(LOGN, '0');
			int j = 0;
			for (auto c : s) {
				if (c == '1') {
					//I need a 0 here to maximise
					if (trie[node][0].first != 0 && trie[node][0].second != 0) {
						mx[j++] = '0';
						node = trie[node][0].first;
					} else {
						if (trie[node][1].second == 0) {
							break;
						}
						mx[j++] = '1';
						node = trie[node][1].first;
					}
				} else {
					//I need a 1 here to maximise
					if (trie[node][1].first != 0 && trie[node][1].second != 0) {
						mx[j++] = '1';
						node = trie[node][1].first;
					} else {
						if (trie[node][0].second == 0) {
							break;
						}
						mx[j++] = '0';
						node = trie[node][0].first;
					}
				}
			}

			int y = 0;
			for (int j = 0; j < LOGN; j++) {
				if (mx[j] == '1') {
					y += 1ll << (LOGN - 1 - j);
				}
			}
			cout << max(x, (y ^ x)) << "\n";
		}
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	//cin >> t;

	while (t--) {
		solve();
	}

	// cerr << "Time elapsed: " << ((long double)clock() / CLOCKS_PER_SEC) << " s.\n";
}

