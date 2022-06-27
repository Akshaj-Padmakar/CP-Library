function<void(int, int)> dfs = [&](int node, int par) {
	sz[node] = 1;
	for (auto ch : g[node]) {
		if (ch ^ par) {
			dfs(ch, node);
			sz[node] += sz[ch];
		}
	}
};
