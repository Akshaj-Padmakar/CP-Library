auto Centroid = [&]() {
	vector<int> centroid;
	vector<int> sz(n + 1);
	function<void (int, int)> dfs = [&](int node, int par) {
		sz[u] = 1;
		bool is_centroid = true;
		for (auto ch : g[node])
			if (ch ^ par) {
				dfs(ch, node);
				sz[node] += sz[ch];

        if (sz[node] > n / 2) {
					is_centroid = false;
				}
        
			}
		if (n - sz[node] > n / 2) {
      is_centroid = false;
    }
		
    if (is_centroid) centroid.push_back(u);
	};
  
	dfs(1, -1);

	return centroid;
};
