function<void(int, int, int)> SSSP_Tree = [&](int node, int p, int d) {
	dis[node] = d;
	for (auto ch : g[node]) {
		if (ch ^ p) {
			SSSP_Tree(ch, node, d + 1);
		}
	}
}


function<int(int, int)> diameter = [&]() {
	SSSP_Tree(1, 0, 0);
	int mx_node = max_element(dis.begin(), dis.end()) - dis.begin();

	dfs(mx_node, 0, 0);

	return max_element(dis.begin, dis.end());
};
