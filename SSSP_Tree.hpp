function<void(int, int, int)> dfs = [&](int node, int p, int d) {
	dis[node] = d;
	for (auto ch : g[node]) {
		if (ch ^ p) {
			dfs(ch, node, d + 1);
		}
	}
}
