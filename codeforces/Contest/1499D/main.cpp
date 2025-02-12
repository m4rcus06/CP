#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int N = (int) 2e7 + 5;

int lp[N], pcount[N];
vector <int> pr;

void solve() {
    int c, d, x;
    cin >> c >> d >> x;

    lli ans = 0;
    for (int g = 1; g * g <= x; ++g) {
        if (x % g == 0) {
            int d1 = g, d2 = x / g;
            if ((x / d1 + d) % c == 0) {
                ans += 1LL << pcount[(x / d1 + d) / c];
            }

            if (d2 != d1) {
                if ((x / d2 + d) % c == 0) {
                    ans += 1LL << pcount[(x / d2 + d) / c];
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif

    for (int i = 2; i < N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.emplace_back(i);
        }
        for (int j = 0; i * pr[j] < N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (lp[i] == pr[j]) break;
        }
    }

    for (const int &x: pr) {
        for (int i = x; i < N; i += x) pcount[i]++;
    }

    int tt = 1;
    cin >> tt;
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