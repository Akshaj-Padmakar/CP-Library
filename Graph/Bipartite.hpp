function<bool(int, int)> dfs = [&](int node, int c) {
	vis[node] = 1;
	col[node] = c;
	for (auto ch : g[node]) {
		if (!vis[ch]) {
			if (!dfs(ch, c ^ 1)) {
				return false;
			}
		} else {
			if (col[node] == col[ch]) {
				return false;
			}
		}
	}
	return true;
};
