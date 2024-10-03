#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

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

using fenw = FenwickTree<int64_t>;
 
void solve() {
    int N, Q; cin >> N >> Q;
    vector <int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector <vector <int>> pos(N + 1, vector <int> (1, 0));
    for (int i = 1; i <= N; ++i) {
        pos[A[i]].push_back(i);
    }

    vector <fenw> f(N + 1);
    for (int i = 1; i <= N; ++i) {
        int sz = pos[i].size();
        f[i] = fenw(sz);
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j < (int) pos[i].size(); ++j) {
            f[i].modify(j, 1LL * pos[i][j] * pos[i][j]);
        }
    }

    int64_t last = 0;
    while (Q--) {
        int type; cin >> type;

        if (type == 1) {
            int p; cin >> p;
            p = (p + last - 1) % (N - 1) + 1;

            if (A[p] == A[p + 1]) continue;
            int &u = A[p];
            int &v = A[p + 1];

            int pu = lower_bound(pos[u].begin(), pos[u].end(), p) - pos[u].begin();
            int pv = lower_bound(pos[v].begin(), pos[v].end(), p + 1) - pos[v].begin();

            f[u].modify(pu, -1LL * p * p + 1LL * (p + 1) * (p + 1));
            f[v].modify(pv, -1LL * (p + 1) * (p + 1) + 1LL * p * p);

            pos[u][pu]++;
            pos[v][pv]--;

            swap(u, v);
        } else if (type == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            l = (l + last - 1) % N + 1;
            r = (r + last - 1) % N + 1;
            x = (x + last - 1) % N + 1;
            if (l > r) swap(l, r);

            int u = lower_bound(pos[x].begin(), pos[x].end(), l) - pos[x].begin();
            int v = upper_bound(pos[x].begin(), pos[x].end(), r) - pos[x].begin() - 1;

            if (u > v || v == 0) {
                last = 0;
            }
            else last = f[x].query(u, v);

            cout << last << '\n';
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            l = (l + last - 1) % N + 1;
            r = (r + last - 1) % N + 1;
            x = (x + last - 1) % N + 1;

            if (l > r) swap(l, r);
            last = f[x].query(l, r);

            cout << last << '\n';
        }
    }
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif
 
    int tt = 1;
    while (tt--) {
        solve();
    }
 
#ifdef LOCAL
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
#endif
 
    return 0;
}
