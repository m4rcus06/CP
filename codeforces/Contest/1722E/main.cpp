#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...)
#endif

const int H = 1000;
const int W = 1000;

void solve() {
    int n, q; cin >> n >> q;
    vector <int> h(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i] >> w[i];
    }

    vector <vector <lli>> S(H + 1, vector <lli> (W + 1, 0));
    for (int i = 0; i < n; ++i) {
        S[h[i]][w[i]] += h[i] * w[i];
    }

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            S[i][j] += S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
        }
    }

    auto query = [&](int x1, int y1, int x2, int y2) -> lli {
        if (x1 > x2 || y1 > y2) return 0LL;
        return S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1];
    };

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ++x1, ++y1, --x2, --y2;
        cout << query(x1, y1, x2, y2) << '\n';
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif

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