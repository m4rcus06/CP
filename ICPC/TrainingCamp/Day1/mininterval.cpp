#include <bits/stdc++.h>
using namespace std;
using lli = long long;

/*How to use:
    Tvector <int, 2> g(n); //graph
    Tvector <int, 3> f(n, k, 2) = f[n][k][2]
*/
template <class Tp, int D = 1>
struct Tvector : public vector<Tvector<Tp, D - 1>> {
    template <class... Args>
    Tvector(int n = 0, Args... args) : vector<Tvector<Tp, D - 1>>(n, Tvector<Tp, D - 1>(args...)) {}
};

template <class Tp>
struct Tvector<Tp, 1> : public vector<Tp> {
    Tvector(int n = 0, Tp val = Tp()) : vector<Tp>(n, val) {}
};

#ifdef LOCAL
#include </home/marcus06/CP/Library/debug.h>
#else
#define debug(...) 
#endif

const int N = int(5e5) + 5;

int n;
lli k, a[N];
int l[N], r[N], f[N];

void update(int p, int i) {
    for (; p <= n; p += p & (-p)) f[p] += i;
}
int query(int p) {
    int res = 0;
    for (; p > 0; p -= p & (-p)) res += f[p];
    return res;
}
int range_query(int l, int r) {
    return query(r) - query(l - 1);
}

vector <array <lli, 3>> queries;
void generate(int lhs, int rhs) {
    if (lhs == rhs) {
        queries.push_back({k - 2LL * a[lhs], lhs, lhs});
        return;
    }

    int mid = (lhs + rhs) >> 1;
    generate(lhs, mid);
    generate(mid + 1, rhs);

    int min_pos = mid;
    for (int i = mid; i >= lhs; --i) {
        if (a[i] < a[min_pos]) min_pos = i;
        else if (a[i] == a[min_pos] && r[i] > r[min_pos]) min_pos = i;

        int ll = mid + 1, rr = min(rhs, r[min_pos] - 1);
        if (ll <= rr) queries.push_back({k - a[i] - a[min_pos], ll, rr});
    }

    min_pos = mid + 1;
    for (int i = mid + 1; i <= rhs; ++i) {
        if (a[i] < a[min_pos]) min_pos = i;
        else if (a[i] == a[min_pos] && l[i] < l[min_pos]) min_pos = i;

        int ll = max(lhs, l[min_pos] + 1), rr = mid;
        if (ll <= rr) queries.push_back({k - a[i] - a[min_pos], ll, rr});
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector <pair <lli, int>> pa;
    for (int i = 1; i <= n; ++i) {
        pa.emplace_back(a[i], i);
    }
    sort(pa.begin(), pa.end());

    stack <int> stk;
    for (int i = 1; i <= n; ++i) {
        while (!stk.empty() && a[stk.top()] > a[i]) stk.pop();
        l[i] = (stk.empty() ? 0 : stk.top());
        stk.push(i);
    }

    while (!stk.empty()) stk.pop();

    for (int i = n; i > 0; --i) {
        while (!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
        r[i] = (stk.empty() ? n + 1 : stk.top());
        stk.push(i);
    }

    generate(1, n);
    sort(queries.begin(), queries.end());

    lli ans = 0;
    int ptr = 0;
    for (int i = 0; i < (int) queries.size(); ++i) {
        auto [bound, lhs, rhs] = queries[i];
        while (ptr < n && pa[ptr].first <= bound) {
            update(pa[ptr].second, 1);
            ptr++;
        }
        ans += range_query(lhs, rhs);
    }

    cout << ans << '\n';
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