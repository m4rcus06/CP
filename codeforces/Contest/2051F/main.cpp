#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...)
#endif

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector <int> a(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i];
    }

    auto merge = [&](vector <pair <int, int>> &s) -> vector <pair <int, int>> {
        sort(s.begin(), s.end());
        vector <pair <int, int>> res = {s[0]};
        for (int i = 0; i < (int) s.size(); ++i) {
            if (s[i].first <= res.back().second + 1) {
                res.back().second = max(res.back().second, s[i].second);
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    };

    vector <pair <int, int>> segments;
    segments.push_back({m, m});
    for (int i = 0; i < q; ++i) {
        vector <pair <int, int>> n_segments;
        for (auto &[l, r] : segments) {
            if (a[i] < l) {
                n_segments.emplace_back(max(1, l - 1), r);
            }
            else if (a[i] > r) {
                n_segments.emplace_back(l, min(n, r + 1));
            } else {
                if (i != 0 || l != r) n_segments.emplace_back(l, r);
                n_segments.emplace_back(1, 1);
                n_segments.emplace_back(n, n);
            }
        }
        segments = merge(n_segments);

        int ans = 0;
        for (auto [l, r] : segments) {
            ans += r - l + 1;
        }
        cout << ans << ' ';
    }
    cout << '\n';
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