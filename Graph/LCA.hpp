vector<vector<int>> dp(n + 1, vector<int>(LOGN, 0ll));
vector<int> depth(n + 1, -1ll);// to normalise with 0

function<void (int, int)> dfs = [&](int node, int par = 0) {
	depth[node] = depth[par] + 1;
	dp[node][0] = par;

	//node-> 2^0 par
	for (int i = 1; i < LOGN; i++) {
		dp[node][i] = dp[dp[node][i - 1]][i - 1];
	}

	for (auto child : g[node]) {
		if (child == par) {
			continue;
		}

		dfs(child, node);
	}
};

function<int (int, int)> ancestor = [&](int node, int k) {
	//par k distnace up !
	for (int i = 0; i < LOGN && node; i++) {
		if (k & (1ll << i)) {
			node = dp[node][i];
		}
	}
	return (node == 0 ? -1 : node);
};

function<int (int, int)> lca = [&](int node1, int node2) {
	if (depth[node1] < depth[node2]) {
		swap(node2, node1);
	}

	node1 = ancestor(node1, depth[node1] - depth[node2]);

	if (node1 == node2)return node1;


	for (int i = LOGN - 1; i >= 0; i--) {
		if (dp[node1][i] != dp[node2][i]) {
			node1 = dp[node1][i];
			node2 = dp[node2][i];
		}
	}

	return dp[node1][0];
};
