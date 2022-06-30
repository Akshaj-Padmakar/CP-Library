//--------------------------------------<INT MATRIX>-------------------------------------------------
const long long MOD2 = static_cast<long long>(MOD) * MOD;

struct Matrix {
    vector< vector<int> > mat;
    int n_rows, n_cols;

    Matrix() {}

    Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}

    static Matrix identity_matrix(int n) {
        vector< vector<int> > values(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const {
        int n = n_rows, m = other.n_cols;
        vector< vector<int> > result(n_rows, vector<int>(n_cols, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                long long tmp = 0;
                for (int k = 0; k < n_cols; k++) {
                    tmp += mat[i][k] * 1ll * other.mat[k][j];
                    while (tmp >= MOD2)
                        tmp -= MOD2;
                }
                result[i][j] = tmp % MOD;
            }

        return move(Matrix(move(result)));
    }

    inline bool is_square() const {
        return n_rows == n_cols;
    }
};

// binary exponentiation, returns a^p
Matrix pw(Matrix a, int p) {
    Matrix result = Matrix::identity_matrix(a.n_cols);
    while (p > 0) {
        if (p & 1)
            result = a * result;
        a = a * a;
        p >>= 1;
    }
    return result;
}



//--------------------------------------<MINT MATRIX>-------------------------------------------------

struct Matrix {
	vector< vector<mint> > mat;
	int n, m;

	Matrix(const vector<vector<mint>>& values) {
		n = values.size(), m = values[0].size();

		mat = values;
	}

	static Matrix identity_matrix(int n) {
		vector< vector<mint> > dum(n, vector<mint>(n, 0));
		for (int i = 0; i < n; i++) {
			dum[i][i] = 1;
		}
		return dum;
	}

	Matrix operator*(const Matrix &other) const {
		assert(m == other.n);

		int szN = n, szK = other.m;

		vector< vector<mint> > ans(szN, vector<mint>(szK, 0));

		for (int i = 0; i < szN; i++) {
			for (int j = 0; j < szK; j++) {
				for (int k = 0; k < m; k++) {
					ans[i][j] += mat[i][k] * other.mat[k][j];
				}
			}
		}

		return ans;
	}
	Matrix operator+(const Matrix &other) const {
		assert(other.n == other.n && other.m == other.m);

		vector<vector<mint>> ans = mat;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans[i][j] += other.mat[i][j];
			}
		}
		return ans;
	}


	Matrix operator-(const Matrix &other) const {
		assert(other.n == other.n && other.m == other.m);

		vector<vector<mint>> ans = mat;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans[i][j] -= other.mat[i][j];
			}
		}
		return ans;
	}

	Matrix binpow(int p)const {
		Matrix result = identity_matrix(m);
		Matrix mul(mat);

		while (p > 0) {
			if (p & 1) {
				result = mul * result;
			}
			mul = mul * mul;
			p >>= 1ll;
		}

		return result;
	}
};



//--------------------------------------<LONG DOUBLE MATRIX>-------------------------------------------------

struct Matrix {
    vector< vector<long double> > mat;
    int n_rows, n_cols;

    Matrix() {}

    Matrix(vector< vector<long double> > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}

    static Matrix identity_matrix(int n) {
        vector< vector< long double> > values(n, vector<long double>(n, 0.0));
        for (int i = 0; i < n; i++)
            values[i][i] = 1.0;
        return values;
    }

    Matrix operator*(const Matrix &other) const {
        int n = n_rows, m = other.n_cols;
        vector< vector<long double> > result(n_rows, vector<long double>(n_cols, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                long double tmp = 0;
                for (int k = 0; k < n_cols; k++) {
                    tmp += mat[i][k] * 1ll * other.mat[k][j];
                    while (tmp >= MOD2)
                        tmp -= MOD2;
                }
                result[i][j] = tmp;
            }

        return move(Matrix(move(result)));
    }

    inline bool is_square() const {
        return n_rows == n_cols;
    }
};

// binary exponentiation, returns a^p
Matrix pw(Matrix a, int p) {
    Matrix result = Matrix::identity_matrix(a.n_cols);
    while (p > 0) {
        if (p & 1)
            result = a * result;
        a = a * a;
        p >>= 1;
    }
    return result;
}

