#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int N = (int) 2e5 + 5;
const lli INF = 1e18 + 7;

struct LazySegmentTree {
    struct Node {
        lli value, add, set;
    };

    int n;
    vector <Node> t;
    
    LazySegmentTree(int _n): n(_n) {
        t.resize(_n << 2, {0, 0, -INF});
    }

    void push(int x) {
        if (t[x].set != -INF) {
            for (int i = 2 * x; i <= 2 * x + 1; ++i) {
                t[i] = {t[x].set, 0, t[x].set};
            }
            t[x].set = -INF;
        } else if(t[x].add != 0) {
            for (int i = 2 * x; i <= 2 * x + 1; ++i) {
                if (t[i].set == -INF) {
                    t[i].add += t[x].add;
                } else {
                    t[i].set += t[x].add;
                    t[i].add = 0;
                }
                t[i].value += t[x].add;
            }
            t[x].add = 0;
        }
    }

    void set(int x, int lt, int rt, int l, int r, int v) {
        if (lt > r || rt < l) return;
        if (lt >= l && rt <= r) {
            t[x].value = t[x].set = v;
            t[x].add = 0;
            return;
        }

        int mt = (lt + rt) / 2;
        push(x);
        set(2 * x, lt, mt, l, r, v);
        set(2 * x + 1, mt + 1, rt, l, r, v);
    }

    void add(int x, int lt, int rt, int l, int r, int v) {
        if (lt > r || rt < l) return;
        if (lt >= l && rt <= r) {
            t[x].value += v;
            if (t[x].set == -INF) t[x].add += v;
            else t[x].set += v;
            return;
        }

        push(x);
        int mt = (lt + rt) / 2;
        add(2 * x, lt, mt, l, r, v);
        add(2 * x + 1, mt + 1, rt, l, r, v);
    }

    lli query(int x, int lt, int rt, int p) {
        if (lt > p || rt < p) return -INF;
        if (lt == p && rt == p) return t[x].value;

        push(x);
        int mt = (lt + rt) / 2;
        if (mt < p) return query(2 * x + 1, mt + 1, rt, p);
        return query(2 * x, lt, mt, p);
    }

    void set(int l, int r, int v) {
        set(1, 1, n, l, r, v);
    }

    void add(int l, int r, int v){
        add(1, 1, n, l, r, v);
    }

    lli query(int p) {
        return query(1, 1, n, p);
    }
};

int n, q;
int a[N], t[N], qr[N];

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> t[i];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> qr[i];
    }

    vector <int> v;
    for (int i = 1; i <= q; ++i) {
        v.emplace_back(qr[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int tree_size = v.size();
    LazySegmentTree tree(tree_size);
    for (int i = 1; i <= tree_size; ++i) {
        tree.set(i, i, v[i - 1]);
    }

    auto work = [&](int i) -> void {
        if (t[i] == 1) {
            tree.add(1, tree_size, a[i]);
        } else if (t[i] == 2) {
            int l = 0, r = tree_size + 1;
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (tree.query(m) <= a[i]) l = m;
                else r = m;
            }
            if (l > 0) tree.set(1, l, a[i]);
        } else {
            int l = 0, r = tree_size + 1;
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (tree.query(m) >= a[i]) r = m;
                else l = m;
            }
            if (r <= tree_size) tree.set(r, tree_size, a[i]);
        }
    };


    for (int i = 1; i <= n; ++i) {
        work(i);
    }

    map <int, lli> f;
    for (int i = 1; i <= tree_size; ++i) {
        f[v[i - 1]] = tree.query(i);
    }

    for (int i = 1; i <= q; ++i) {
        cout << f[qr[i]] << ' ';
    }
    cout << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("FILTERS.INP", "r", stdin);
    freopen("FILTERS.OUT", "w", stdout);
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
