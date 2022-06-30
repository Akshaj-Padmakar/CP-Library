/*
Instructions :
         *> Done with path-compression and Union-by-rank
	 *> intialise = O(n), find = O(α(n)), merge = O(α(n)), same = O(α(n)),groups = O(n*α(n))
*/

struct dsu {
public:
	dsu(int _n) {
		n = _n;
		par.assign(n, 0);
		sz.assign(n, 1);
		for (int i = 0; i < n; i++) {
			par[i] = i;
		}
	}

	int find(int v) {
		assert(v >= 0 && v < n);
		if (v == par[v]) {
			return v;
		}
		return par[v] = find(par[v]);
	}

	void merge(int u, int v) {
		assert(u >= 0 && u < n && v >= 0 && v < n);

		u = find(u), v = find(v);
		if (u == v) {
			return;
		}
		if (sz[u] > sz[v]) {
			swap(u, v);
		}
		par[u] = v;
		sz[v] += sz[u];
	}

	int size(int u) {
		assert(u >= 0 && u < n);
		u = find(u);
		return sz[u];
	}

	bool same(int u, int v) {
		assert(u >= 0 && u < n && v >= 0 && v < n);

		return find(u) == find(v);
	}

	void groups(vector<vector<int>> &grp) {
		vector<vector<int>> temp(n);
		for (int i = 0; i < n; i++ ) {
			temp[find(i)].push_back(i);
		}

		for (int i = 0; i < n; i++) {
			if (temp[i].size() >= 1) {
				grp.push_back(temp[i]);
			}
		}
	}

private:
	int n;
	vector<int> par, sz;
};
