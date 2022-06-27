function<void(int)> dijktra = [&](int source) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	//dis,node

	pq.push({source, 0});


	while (pq.size()) {
		auto [d, node] = pq.top();
		pq.front();

		for (auto [ch, w] : g[node]) {
			if (dis[ch] > dis[node] + w) {
				dis[ch] = dis[node] + w;
				pq.push(dis[ch], ch);
			}
		}
	}
};
