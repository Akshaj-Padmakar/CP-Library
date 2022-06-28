int log2_ceil(int n) {
	int x = 0;
	while ((1ll << x) < (int)(n)) {
		x++;
	}
	return x;
}
template<typename Monoid> struct SegmentTree {
	using F = function<Monoid(Monoid, Monoid)>;
 
	SegmentTree(int n, const F op, const Monoid e) {
		_n = n;
		_op = op;
		_e = e;
 
		sz = log2_ceil(n);
		seg.assign(2 * sz, _e);
	}
	SegmentTree(vector<Monoid> v, const F op, const Monoid e) {
		_n = v.size();
		_op = op;
		_e = e;
 
		sz = (1ll << log2_ceil(_n));
		seg.assign(2 * sz, _e);
 
		for (int i = 0; i < _n; i++) {
			update(i, v[i]);
		}
 
	}
 
	void update(int k, const Monoid &x) {
		assert(k >= 0 && k < _n);
		k += sz;
		seg[k] = x;
		while (k >>= 1) {
			seg[k] = _op(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}
	Monoid query(int l, int r) {
		assert(0 <= l && l <= r && r <= _n);
 
		Monoid ansL = _e, ansR = _e;
 
		l += sz, r += sz;
 
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) {
				ansL = _op(ansL, seg[l++]);
			}
			if (r & 1) {
				ansR = _op(seg[--r], ansR);
			}
		}
		return _op(ansL, ansR);
	}
 
	Monoid operator[](const int &k) const {
		return seg[k + sz];
	}
 
	template< typename C >int find_subtree(int a, const C &check, Monoid &M, bool type) {
		while (a < sz) {
			Monoid nxt = type ? _op(seg[2 * a + type], M) : _op(M, seg[2 * a + type]);
			if (check(nxt)) {
				a = 2 * a + type;
			} else {
				M = nxt, a = 2 * a + 1 - type;
			}
		}
		return a - sz;
	}
 
 
	template< typename C >int find_first(int l, const C &check) {
		assert(l >= 0 && l < _n);
		Monoid ansL = _e;
		if (l <= 0) {
			if (check(_op(ansL, seg[1]))) {
				return find_subtree(1, check, ansL, false);
			}
			return -1;
		}
		int r = 2 * sz;
		l += sz;
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) {
				Monoid nxt = _op(ansL, seg[l]);
				if (check(nxt)) {
					return find_subtree(l, check, ansL, false);
				}
				ansL = nxt;
				++l;
			}
		}
		return -1;
	}
 
	template< typename C >int find_last(int r, const C &check) {
		assert(r >= 0 && r < _n);
		Monoid ansR = _e;
		if (r >= sz) {
			if (check(_op(seg[1], r))) {
				return find_subtree(1, check, r, true);
			}
			return -1;
		}
		int l = sz; r += sz;
		for (; l < r; l >>= 1, r >>= 1) {
			if (r & 1) {
				Monoid nxt = _op(seg[--r], ansR);
				if (check(nxt)) {
					return find_subtree(r, check, ansR, true);
				}
				ansR = nxt;
			}
		}
		return -1;
	}
private:
	int _n;
	int sz;
	vector<Monoid> seg;
 
	F _op;
	Monoid _e;
};
 
 
const int INF = 1e17;
int op(int a, int b) { return max(a, b); }
int e = -INF;
