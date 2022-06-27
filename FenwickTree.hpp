template <class T> struct fenwick_tree {
public:
    fenwick_tree() : _n(0) {}

    fenwick_tree(int n) : _n(n), data(n) {}

    void add(int i, T delta) {
        assert(0 <= i && i < _n);
        i++;
        while (i <= _n) {
            data[i - 1] += (delta);
            i += i & -i;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);

        return sum(r) - sum(l);
    }

private:
    int _n;
    vector<T> data;

    T sum(int r) {
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};
