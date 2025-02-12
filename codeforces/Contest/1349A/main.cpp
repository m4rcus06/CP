#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int N = (int) 1e5 + 5;
const int inf = 1e9 + 7;

int n, a[N], mn[2 * N], pw[2 * N];

lli binpow(lli a, int n) {
    lli res = 1;
    while (n) {
        if (n & 1) res = 1LL * res * a;
        a = 1LL * a * a;
        n >>= 1;
    }
    return res;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    int max_a = *max_element(a, a + n);
    for (int i = 1; i <= max_a; ++i) mn[i] = pw[i] = inf;

    vector <int> cnt_p(max_a + 1, 0);
    for (int i = 0; i < n; ++i) {
        int v = a[i];
        for (int d = 2; d * d <= v; ++d) {
            if (v % d == 0) {
                int cnt = 0;
                while (v % d == 0) {
                    cnt++;
                    v /= d;
                }

                int cur = max(mn[d], cnt);
                pw[d] = min(pw[d], cur);
                if (i > 0 && cnt_p[d] < i) pw[d] = min(pw[d], cnt);

                cnt_p[d]++;
                mn[d] = min(mn[d], cnt);
            }
        }
        if (v > 1) {
            int cur = max(mn[v], 1);
            pw[v] = min(pw[v], cur);
            if (i > 0 && cnt_p[v] < i) pw[v] = min(pw[v], 1);

            cnt_p[v]++;
            mn[v] = min(mn[v], 1);
        }
    }

    //3 4 4 4 2 3
    lli ans = 1;
    for (int i = 1; i <= max_a; ++i) {
        if (cnt_p[i] == n - 1) pw[i] = mn[i];
        else if (cnt_p[i] < n - 1) pw[i] = 0;
        if (pw[i] != inf) ans *= binpow(i, pw[i]);
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