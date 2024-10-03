template <typename T>
class FenwickTree {
private:
    int N, pw;
    vector<T> bit;

public:
    FenwickTree(): N(0) {}
    FenwickTree(int _N): N(_N){
        bit.resize(N + 1);
        pw = bit_floor(N);
    }

    int size() const {
        return N;
    }

    void modify (int u, T delta) {
        assert(0 < u && u <= N);
        for (; u <= N; u += u & -u) bit[u] += delta;
    }

    //doesn't matter if u == 0, it will return 0;
    T query (int u) const {
        assert(u <= N);

        T res(0);
        for (; u > 0; u -= u & -u) res += bit[u];
        return res;
    }

    T query (int l, int r) const {
        assert(0 < l && l <= r && r <= N);
        return query(r) - query(l - 1);
    }

    int MaxPrefix(T ub) {
        T v(0);
        int p = 0;

        for (int i = pw; i > 0; i >>= 1) {
            if (p + i <= N) {
                T nxt = v;
                nxt += bit[p + i];

                if (nxt <= ub) {
                    v = nxt;
                    p += i;
                }
            }
        }
        assert(p <= N);
        return p;
    }

    void reset() {
        fill(bit.begin(), bit.end(), T(0));
    }
};
