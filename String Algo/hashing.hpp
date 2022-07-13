const int MOD = 1e9 + 7;
const int MOD2 = 998244353;

template< int mod >struct ModInt {
public:
	int x;
	ModInt() : x(0) {}

	ModInt(int _x) {
		_x %= mod; _x += mod; _x %= mod;
		x = _x;
	}

	ModInt &operator+=(const ModInt &_x) {
		x += _x.x;
		if (x >= mod) {
			x -= mod;
		}
		return *this;
	}

	ModInt &operator-=(const ModInt &_x) {
		x -= _x.x;
		if (x < 0) {
			x += mod;
		}
		return *this;
	}

	ModInt &operator*=(const ModInt &_x) {
		x *= _x.x; x %= mod;

		return *this;
	}

	ModInt &operator/=(const ModInt &_x) {
		*this *= _x.inverse();
		return *this;
	}

	ModInt operator-() const {return ModInt(-x); }

	ModInt operator+(const ModInt &_x) const { return ModInt(*this) += _x; }

	ModInt operator-(const ModInt &_x) const { return ModInt(*this) -= _x; }

	ModInt operator*(const ModInt &_x) const { return ModInt(*this) *= _x; }

	ModInt operator/(const ModInt &_x) const { return ModInt(*this) /= _x; }

	bool operator==(const ModInt &_x) const { return x == _x.x; }

	bool operator!=(const ModInt &_x) const { return x != _x.x; }

	ModInt inverse() const {
		int a = x, b = mod, u = 1, v = 0, t;
		while (b > 0) {
			t = a / b;
			swap(a -= t * b, b);
			swap(u -= t * v, v);
		}
		return ModInt(u);
	}

	ModInt binpow(int n) const {
		ModInt ans(1), mul(x);
		while (n > 0) {
			if (n & 1) {
				ans *= mul;
			}
			mul *= mul;
			n >>= 1;
		}
		return ans;
	}

	friend ostream &operator<<(ostream &os, const ModInt &p) {
		return os << p.x;
	}

	friend istream &operator>>(istream &is, ModInt &a) {
		int t;
		is >> t;
		a = ModInt< mod >(t);
		return (is);
	}

private:
};

using mint = ModInt< MOD >;
using mint2 = ModInt< MOD2 >;

template<class modInt>struct stringHash {
public:
	stringHash(string &s, int base) {
		_n = s.size();
		_base = base;
		_Ibase = _base.inverse();

		hashF.resize(_n);
		pw.resize(_n);
		inv.resize(_n);


		for (int i = 0; i < _n; i++) {
			pw[i] = _base.binpow(i);
			inv[i] = _Ibase.binpow(i);
		}

		hashF[0] = modInt(s[0] - 'a' + 1);
		for (int i = 1; i < _n; i++) {
			hashF[i] = hashF[i - 1] + pw[i] * (modInt(s[i] - 'a' + 1ll));
		}
	}

	modInt get(int i, int j) {
		if (i == 0) {
			return hashF[j];
		}
		return (hashF[j] - hashF[i - 1]) * inv[i];
	}
private:
	//int base = 31;
	int _n;
	modInt _base, _Ibase;
	vector<modInt> hashF, pw, inv;
};

