#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long


void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> e;
	vector<vector<int>> g(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		e.push_back({a, b});
	}


	auto eulerian_path = [&](int src, bool directed) {
		vector<vector<pair<int, int>>> g(n + 1);
		//{node} -> {child,check}
		for (auto [x, y] : e) {
			int id1 = g[x].size(), id2 = g[y].size();
			g[x].push_back({y, id2 - 1});
			if (!directed) {
				g[y].push_back({x, id1 - 1});
			}
		}

		stack<pair<int, pair<int, int>>> st;
		st.push({src, { -1, -1}});

		vector<pair<int, int>> ans;
		while (st.size()) {
			auto node = st.top().first;

			if (g[node].size()) {
				auto ch = g[node].back();
				g[node].pop_back();

				if (ch.second == -1) {
					continue;
				}

				if (!directed) {
					g[ch.first][ch.second].second = -1;
				}

				st.push({ch.first, {ch.first, node}});
			} else {
				ans.push_back(st.top().second);
				st.pop();
			}
		}
		ans.pop_back();
		reverse(begin(ans), end(ans));
		if (ans.size() != n) return vector<pair<int, int>> {};
		return ans;
	};

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

