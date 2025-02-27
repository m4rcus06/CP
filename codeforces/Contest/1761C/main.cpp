#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int n; cin >> n;
    vector <string> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector <set <int>> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i].insert(i + 1);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (b[i][j] == '1') ans[j].insert(ans[i].begin(), ans[i].end());
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i].size() << ' ';
        for (auto it: ans[i]) cout << it << ' ';
        cout << '\n';
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