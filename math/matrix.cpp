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
};

template<typename T>
matrix<T> multiply(const matrix<T> &a, const matrix<T> &b) {
    assert(a.col_nums() == b.row_nums());
    int n = a.row_nums();
    int p = b.col_nums();
    int m = b.row_nums();

    matrix<T> res(n, p);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= p; ++j) {
            for (int k = 1; k <= m; ++k) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return res;
}

template<typename T>
matrix<T> add(const matrix<T> &a, T val) {
    int n = a.row_nums();
    int m = a.col_nums();

    matrix<T> res(n, m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            res[i][j] = a[i][j] + val;
        }
    }

    return res;
}

template<typename T>
matrix<T> add(const matrix<T> &a, const matrix<T> &b) {
    assert(a.col_nums() == b.col_nums() && a.row_nums() == b.row_nums());

    int n = a.row_nums();
    int m = a.col_nums();

    matrix<T> res(n, m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }

    return res;
}

template<typename T>
matrix<T> pow(const matrix<T> &a, int64_t n) {
    matrix<T> tmp = a;
    matrix<T> res = a;
    while (n > 0) {
        if (n & 1) res = multiply(res, tmp);
        tmp = multiply(tmp, tmp);
        n >>= 1;
    }
    return res;
}

void solve() {
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int tt = 1;
    while(tt--) {
        solve();
    }
    return 0;
}