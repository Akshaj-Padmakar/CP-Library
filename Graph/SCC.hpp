//Kosaraju's Algorithm.

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>g(n + 1), rg(n + 1);//transposed graph

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		rg[b].push_back(a);
	}

	vector<bool> vis(n + 1, false);
	vector<int> out;
	function<void(int)> dfs = [&](int node) {
		vis[node] = 1;
		for (auto ch : g[node]) {
			if (!vis[ch]) {
				dfs(ch);
			}
		}
		out.push_back(node);
	};
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}

	fill(vis.begin(), vis.end(), false);

	vector<int> ne;
	function<void(int)> dfs2 = [&](int node) {
		vis[node] = 1;
		for (auto ch : rg[node]) {
			if (!vis[ch]) {
				dfs2(ch);
			}
		}
		ne.push_back(node);
	};
	vector<vector<int>> ans;//stores the strongly connected componenet
	for (int i = n - 1; i >= 0; i--) {
		if (!vis[out[i]]) {
			ne.clear();
			dfs2(out[i]);
			ans.push_back(ne);
		}
	}

}
