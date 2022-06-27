function<void(int)> bfs = [&](int source) {
	queue<int> q;
	q.push(source);
	dis[source] = 0;

	while (q.size()) {
		auto node = q.front();
		q.pop();

		for (auto ch : g[node]) {
			if (dis[ch] > dis[node] + 1) {
				dis[ch] = dis[node] + 1;
				q.push(ch);
			}
		}
	}
};
