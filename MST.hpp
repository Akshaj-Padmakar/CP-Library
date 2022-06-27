void solvethetestcase() {
	int n, m;
	cin >> n >> m;

	dsu ds(n);

	vector<pair<int, pii>> G;
	rep(i, m) {
		int a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		G.pb({w, {a, b}});
	}

	sort(all(G));
	// on the basis of weight

	int ans = 0;
	rep(i, m) {
		int a = G[i].S.F;
		int b = G[i].S.S;
		int w = G[i].F;

		if (ds.same(a, b)) {
			//ok

		} else {
			ans += w;
			ds.merge(a, b);
		}
	}
	if (ds.groups().size() > 1) {
		cout << -1 << "\n";
		return;
		// we had dis-connected graph intially!
	}

	cout << ans << "\n";
}

