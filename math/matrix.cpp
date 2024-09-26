#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </Coding/Library/debug.h>
#else
#define debug(...)
#endif

template <typename T>
class matrix {
private:
    int n, m;
    vector<vector<T>> mat;

public:
    matrix(int n, int m): n(n), m(m) {
        mat.resize(n + 1, vector<T>(m + 1, {}));
    };

    int row_nums() const {
        return n;
    }

    int col_nums() const {
        return m;
    }

    vector<T>& operator[](int i) {
        return mat[i];
    }

    const vector<T>& operator[](int i) const {
        return mat[i];
    }

    static matrix<T> I(int n) {
        matrix<T> res(n, n);
        for (int i = 1; i <= n; ++i) {
            res[i][i] = 1;
        }
        return res;
    }

    matrix<T> operator* (const matrix<T> &b) {
        assert(n == b.row_nums());

        int p = b.col_nums();

        matrix<T> res(n, p);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= p; ++j) {
                for (int k = 1; k <= m; ++k) {
                    res[i][j] += mat[i][k] * b[k][j];
                }
            }
        }

        return res;
    }

    matrix<T> operator+ (T val) {
        matrix<T> res(n, m);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                res[i][j] = mat[i][j] + val;
            }
        }

        return res;
    }

    matrix<T> operator+ (const matrix<T> &b) {
        assert(n == b.col_nums() && m == b.row_nums());

        matrix<T> res(n, m);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                res[i][j] = mat[i][j] + b[i][j];
            }
        }

        return res;
    }

    static matrix<T> pow(const matrix<T> &a, int64_t n) {
        int sz = a.row_nums();

        matrix<T> tmp = a;
        matrix<T> res = I(sz);
        while (n > 0) {
            if (n & 1) res = res * tmp;
            tmp = tmp * tmp;
            n >>= 1;
        }
        return res;
    }
};

using mat = matrix<int>;

void solve() {
    mat a(2, 2);
    a[1][1] = 1;
    a[1][2] = 3;
    a[2][1] = 0;
    a[2][2] = 1;

    a = mat::pow(a, 200);
    cout << a[1][2];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int tt = 1;
    while(tt--) {
        solve();
    }
    return 0;
}