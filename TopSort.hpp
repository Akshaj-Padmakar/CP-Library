
function<void(int)> kahn = [&]() {
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (in[i] == 0) {
				q.push(i);
			}
		}

		while (q.size()) {
			int node = q.front();
			q.pop();
			tpsrt.push_back(node);

			for (auto ch : g[node]) {
				in[ch]--;
				if (!in[ch]) {
					q.push(ch);
				}
			}
		}
		assert((int)ans.size() == n);
		//Check for a DAG
	}
