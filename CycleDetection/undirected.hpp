//any edge that connects it to its ancestor which is not its parent is called a "BACK-EDGE"
//BACK-EDGE indicates a cycle in the graph

//Create a parent array and back-track from node to ch

function<bool(int, int)> dfs = [&](int node, int p) {
	vis[node] = 1;
	for (auto ch : g[node]) {
		if (vis[ch]) {
			if (ch != p) {
				return true;
			}
		} else {
			if (dfs(ch, node)) {
				return true;
			}
		}
	}
	return false;
};
