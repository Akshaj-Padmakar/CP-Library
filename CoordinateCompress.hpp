auto coo_compress = [&](vector<int> &x) {
    // coordinates compresse x and over-writes on it !
    int sz = x.size(), id = 0;
    map<int, int> mp;

    for (int i = 0; i < sz; i++) {
        mp[x[i]] = 1;
    }

    for (auto x : mp) {
        mp[x.first] = id++;
    }

    for (int i = 0; i < sz; i++) {
        x[i] = mp[x[i]];
    }
};
