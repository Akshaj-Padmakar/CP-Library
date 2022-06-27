bool isprime(int n) {
	bool ok = true;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ok = false;
			break;
		}
	}
	return ok;
}

bool isPrimeRand(int n) {
    if (n < 2) {
        return false;
    }
    for (int x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == x) {
            return true;
        }
        bool flag = true;
        int r = 1;
        int t = 1;
        while (r <= ((n - 1) >> __builtin_ctzll(n - 1))) {
            if (r & ((n - 1) >> __builtin_ctzll(n - 1))) {
                t = ((__int128)t * x) % n;
            }
            x = ((__int128)x * x) % n;
            r <<= 1;
        }
        if (t == 1 || t == n - 1) {
            flag = false;
        }
        for (r = 0; r < __builtin_ctzll(n - 1); r++) {
            t = ((__int128)t * t) % n;
            if (t == n - 1)
                flag = false;
        }
        if (flag)
            return false;
    }
    return true;
}
