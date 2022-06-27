const int MOD = 998244353;
const int MAXN = 2e5 + 5;

template<typename T> T gcd(T a, T b) {if (b == 0) return a; a %= b; return gcd(b, a);}
template<typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}

int add(int a, int b, int c = MOD) {int res = a + b; return (res >= c ? res % c : res);}
int sub(int a, int b, int c = MOD) {int res; if (abs(a - b) < c)res = a - b; else res = (a - b) % c; return (res < 0 ? res + c : res);}
int mul(int a, int b, int c = MOD) {int res = (long long)a * b; return (res >= c ? res % c : res);}

template<typename T>T binpow(T e, T n) {T x = 1, p = e; while (n) {if (n & 1)x = x * p; p = p * p; n >>= 1;} return x;}
template<typename T>T binpow2(T e, T n, T m = MOD) {T x = 1, p = e; while (n) {if (n & 1)x = mul(x, p, m); p = mul(p, p, m); n >>= 1;} return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y) {
    T xx = 0, yy = 1; y = 0; x = 1; while (b) {
        T q = a / b, t = b; b = a % b; a = t; \
        t = xx; xx = x - q * xx; x = t; t = yy; yy = y - q * yy; y = t;
    } return a;
}
template<typename T>T mod_inverse(T a, T n = MOD) {T x, y, z = 0; T d = extended_euclid(a, n, x, y); return (d > 1 ? -1 : sub(x, z, n));}


const int FACSZ = 5005; // Make sure to change this


vector<int> fact(FACSZ), ifact(FACSZ);
// factorial and inverse factorial
// till FACSZ

void precom(int c = MOD) {
    fact[0] = 1;
    for (int i = 1; i < FACSZ; i++) {
        fact[i] = mul(i, fact[i - 1], c);
    }

    ifact[FACSZ - 1] = mod_inverse(fact[FACSZ - 1], c);
    for (int i = FACSZ - 2; i >= 0; i--) {
        ifact[i] = mul(i + 1, ifact[i + 1], c);
    }
}

vector<int> primes;
void prime_precom() {
    /*
    size     last prime
    78499 -> ~1e6
    1e5   -> ~1299743 (1.2s)
    1e5   -> ~15485917 (8s)
    */
    primes.push_back(2);
    for (int x = 3; primes.size() <= MAXN; x += 2) {
        bool isPrime = true;
        for (auto p : primes) {
            if (x % p == 0) {
                isPrime = false; break;
            }
            if (p * p > x) {
                break;
            }
        }
        if (isPrime) {
            primes.push_back(x);
        }
    }
}
int ncr(int n, int k) {
    //O(k)
    if (n < k)
        return 0;
    if (k == 0)
        return 1;
    int res = 1; if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i) {
        res *= (n - i); res /= (i + 1);
    }
    return res;
}
int ncr_modp(int n, int k, int c = MOD) {
    //O(k)
    if (n < k) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }

    int res = 1;

    if (k > n - k) {
        k = n - k;
    }
    for (int i = 0; i < k; ++i) {
        res = mul(res, n - i, c);
        res = mul(res, binpow2(i + 1, c - 2, c), c);
    }
    return res;
}


void factorize(int a, vector<int> &factors) {
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            factors.push_back(i);
            factors.push_back(a / i);
        }
    }
    sort(factors.begin(), factors.end());
}

int ncr_precom(int n, int r, int c = MOD) {
    //define fact and ifact first
    return mul(mul(ifact[r], ifact[n - r], c), fact[n], c);
}
int ceil(int a, int b) {
    return (a + b - 1) / b;
}
bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if ( n % i == 0 ) {
            return 0;
        }
    }
    return 1;
}

//could be MLE
vector<int> spf;
void sieve() {
    spf.resize(MAXN);
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        spf[i] = i;
    }
    for (int i = 4; i < MAXN; i += 2) {
        spf[i] = 2;
    }
    for (int i = 3; i * i <= MAXN; i += 2) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}
//Linear Sieve !
void sieve() {
    spf.resize(MAXN);
    spf[1] = 1;
    for (int i = 2; i < MAXN; i += 2) {
        spf[i] = 2;
    }

    for (int i = 3; i < MAXN; i += 2) {
        spf[i] = i;
    }
    vector<int> pp;
    for (int i = 3; i < MAXN; i += 2) {
        if (spf[i] == i) {
            pp.push_back(i);
        }
        for (int j = 0; j < pp.size() && spf[j] * i < MAXN; j++) {
            if (i % pp[j] == 0) {
                //not a spf now !
                break;
            }
            spf[i * pp[j]] = pp[j];
        }
    }
}


void pfactor(int x, vector<int> &pfac) {
    while (x != 1) {
        pfac.push_back(spf[x]);
        int z = spf[x];
        while (x % z == 0) {
            x /= z;
        }

    }
}
