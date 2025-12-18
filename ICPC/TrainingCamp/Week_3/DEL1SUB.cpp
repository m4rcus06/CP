#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const int mxN = 2e5 + 5;
const lli inf = lli(1e18) + 7;

mt19937 rng(clock());
int get_rand(int l, int r) {
    return l + rng() % (r - l + 1);
}


struct Node {
    lli first_val, last_val;
    lli sum[2], max_pref[2], max_suf[2];
    lli f[2];

    Node() {
        first_val = last_val = -inf;
        for (int i = 0; i < 2; ++i) {
            sum[i] = max_pref[i] = max_suf[i] = f[i] = -inf;
        }
    }

    Node(lli v) {
        sum[0] = v;
        first_val = last_val = v;
        f[0] = max_pref[0] = max_suf[0] = v;
        sum[1] = f[1] = max_pref[1] = max_suf[1] = -inf;
    }

    void dbg() {
        cerr << "first_val: " << first_val << ", last_val: " << last_val << '\n';
        for (int i = 0; i < 2; ++i) {
            cerr << "sum[" << i << "]: " << sum[i] << '\n';
            cerr << "max_pref[" << i << "]: " << max_pref[i] << '\n';

            cerr << "max_suf[" << i << "]: " << max_suf[i] << '\n';

            cerr << "f[" << i << "]: " << f[i] << '\n';
        }
    }
};

struct SegmentTree {
    int n;
    vector <Node> t;

    SegmentTree(int _n): n(_n) {
        t.resize(n << 2);
    }

    Node merge(const Node &lhs, const Node &rhs) {
        Node res;
        if (rhs.first_val == inf) return lhs;
        if (lhs.first_val == inf) return rhs;

        res.first_val = lhs.first_val;
        res.last_val = rhs.last_val;
        res.sum[0] = lhs.sum[0] + rhs.sum[0];
        res.sum[1] = max(lhs.sum[0] - min(lhs.first_val, lhs.last_val) + rhs.sum[0], lhs.sum[0] + rhs.sum[0] - min(rhs.first_val, lhs.first_val));
        res.sum[1] = max(res.sum[1], lhs.sum[1] + rhs.sum[0]);
        res.sum[1] = max(res.sum[1], lhs.sum[0] + rhs.sum[1]);

        res.max_pref[0] = max(lhs.max_pref[0], lhs.sum[0] + rhs.max_pref[0]);
        res.max_suf[0] = max(rhs.max_suf[0], rhs.sum[0] + lhs.max_suf[0]);

        res.max_pref[1] = max(lhs.max_pref[1], lhs.sum[0] - min(lhs.first_val, lhs.last_val) + rhs.max_pref[0]);
        res.max_pref[1] = max(res.max_pref[1], lhs.sum[0] + rhs.max_pref[1]);
        res.max_pref[1] = max(res.max_pref[1], lhs.sum[1] + rhs.max_pref[0]);

        res.max_suf[1] = max(rhs.max_suf[1], rhs.sum[0] - min(rhs.first_val, rhs.last_val) + lhs.max_suf[0]);
        res.max_suf[1] = max(res.max_suf[1], rhs.sum[0] + lhs.max_suf[1]);
        res.max_suf[1] = max(res.max_suf[1], rhs.sum[1] + lhs.max_suf[0]);

        res.f[0] = max({lhs.f[0], rhs.f[0], lhs.max_suf[0] + rhs.max_pref[0]});

        res.f[1] = max(lhs.f[1], rhs.f[1]);
        res.f[1] = max(res.f[1], lhs.max_suf[1] + rhs.max_pref[0]);
        res.f[1] = max(res.f[1], lhs.max_suf[0] + rhs.max_pref[1]);
        return res;
    }

    void update(int x, int lhs, int rhs, int pos, lli value) {
        if (lhs > pos || rhs < pos) return;
        if (lhs == rhs) {
            t[x] = Node(value);
            return;
        }

        int mid = (lhs + rhs) >> 1;
        update(2 * x, lhs, mid, pos, value);
        update(2 * x + 1, mid + 1, rhs, pos, value);
        t[x] = merge(t[2 * x], t[2 * x + 1]);
    }

    void update(int pos, lli value) {
        update(1, 1, n, pos, value);
    }

    Node query(int x, int lhs, int rhs, int l, int r){
        if (lhs > r || rhs < l) return Node(-inf);
        if (lhs >= l && rhs <= r) {
            //cerr << "inside range, L: " << lhs << " R: " << rhs << '\n';
            //t[x].dbg();
            //cerr << '\n';
            return t[x];
        }

        int mid = (lhs + rhs) >> 1;
        Node L = query(2 * x, lhs, mid, l, r);
        Node R = query(2 * x + 1, mid + 1, rhs, l, r);
        if (L.first_val == -inf) return R;
        if (R.first_val == -inf) return L;
        return merge(L, R);
    }

    Node query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

struct Query {
    int t, l, r;
} Q[mxN];

int n, q, a[mxN];
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= q; ++i) {
        cin >> Q[i].t >> Q[i].l >> Q[i].r;
    }

    SegmentTree tree(n);
    for (int i = 1; i <= n; ++i) {
        tree.update(i, a[i]);
    }

    for (int i = 1; i <= q; ++i) {
        int t = Q[i].t;
        if (t == 1) {
            int p = Q[i].l, x = Q[i].r;
            tree.update(p, x);
        } else {
            int l = Q[i].l, r = Q[i].r;
            Node res = tree.query(l, r);
            cout << (max(res.f[0], res.f[1])) << '\n';
        }
    }
}

int main() {
    //freopen("in.inp", "r", stdin);
    cin.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
