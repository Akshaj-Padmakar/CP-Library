function<void(int)> dfs = [&](int node) {
	vis[node] = 1;
	in[node] = timer++;

	for (auto ch : g[node]) {
		if (!vis[ch]) {
			dfs(ch);
		}
	}
	out[node] = timer++;
};

function<bool(int)> isAncestor = [&](int ancestor, int child) {
	return in[ancestor] <= in[child] && out[ancestor] >= out[child];
};

