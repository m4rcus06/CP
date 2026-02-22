#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const lli inf = lli(1e18) + 7;

struct SegmentTree {
    int n;
    vector <lli> t;

    SegmentTree(int _n): n(_n) {
        t.resize(n << 2);
    }

    void update(int x, int lhs, int rhs, int pos, lli v) {
        if (lhs > pos || rhs < pos) return;
        if (lhs == rhs) {
            t[x] = v;
            return;
        }
        int mid = (lhs + rhs) >> 1;
        update(2 * x, lhs, mid, pos, v);
        update(2 * x + 1, mid + 1, rhs, pos, v);
        t[x] = min(t[2 * x], t[2 * x + 1]);
    }

    lli query(int x, int lhs, int rhs, int l, int r) {
        if (lhs > r || rhs < l) return inf;
        if (lhs >= l && rhs <= r) return t[x];
        int mid = (lhs + rhs) >> 1;
        return min(query(2 * x, lhs, mid, l, r), query(2 * x + 1, mid + 1, rhs, l, r));
    }

    void update(int pos, lli v) {
        update(1, 1, n, pos, v);
    }

    lli query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

int solve1(int n, const vector <int> &a) {
    vector <lli> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector <pair <int, lli>> dp(n + 1, make_pair(n - 1, lli(1e18) + 7));
    dp[1] = {0, pref[1]};
    dp[0] = {0, 0};
    for (int i = 2; i <= n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (pref[i] - pref[j] >= dp[j].second) {
                dp[i] = min(dp[i], make_pair(dp[j].first + i - j - 1, pref[i] - pref[j]));
            }
        }
    }

    return dp[n].first;
}

int solve3(int n, const vector <int> &a) {
    vector <lli> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    SegmentTree tree(n);
    vector <lli> f(n + 1);
    f[1] = pref[1];
    tree.update(1, f[1] + pref[1]);
    for (int i = 2; i <= n; ++i) {
        int l = 0, r = i;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (tree.query(mid, i - 1) <= pref[i]) l = mid;
            else r = mid;
        }
        f[i] = pref[i] - pref[l];
        tree.update(i, f[i] + pref[i]);
    }

    int p = n - 1, ans = 0;
    while (p >= 0) {
        lli need = f[p + 1], sum = 0;
        int j = p;
        while (j >= 0) {
            if (sum == need) break;
            sum += a[j];
            j--;
        }
        ans += p - j - 1;
        p = j;
    }
    return ans;
}


int solve2(int n, const vector <int> &a) {
    vector <lli> f(n);
    f[0] = a[0];
    for (int i = 1; i < n; ++i) {
        lli sum = a[i];
        for (int j = i - 1; j >= 0; --j) {
            if (sum >= f[j]) break;
            sum += a[j];
        }
        f[i] = sum;
    }

    int p = n - 1, ans = 0;
    while (p >= 0) {
        lli need = f[p], sum = 0;
        int j = p;
        while (j >= 0) {
            if (sum == need) break;
            sum += a[j];
            j--;
        }
        ans += p - j - 1;
        p = j;
    }
    return ans;
}

mt19937 rng(30052006);

int Rand(int l, int r) {
    return l + rng() % (r - l + 1);
}

void gen() {
    int n;
    vector <int> a;
    for (int _ = 0; _ < 10000; ++_) {
        n = 5000;
        a.clear();
        a.resize(n);
        for (auto &x: a) x = Rand(1, 200000);

        lli x = solve1(n, a), y = solve2(n, a), z = solve3(n, a);
        if (x != y || y != z || x != z) {
            cerr << "WRONG";
            cout << n << '\n';
            for (auto x: a) cout << x << ' ';
            return;
        } else {
            cerr << "PASSED" << '\n';
        }
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    freopen("test.inp", "w", stdout);
    gen();
    return 0;
}


