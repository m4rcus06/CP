#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

int ask(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int x; cin >> x;
    return x;
}

void solve() {
    int n; cin >> n;

    vector <pair <int, int>> edges;
    map <pair <int, int>, int> cache;
    function <void(int, int)> find = [&](int x, int y) {
        int u = ask(x, y);
        if (u == x) {
            edges.emplace_back(x, y);
            return;
        }
        find(u, y);
    };

    for (int i = 2; i <= n; ++i) {
        find(1, i);
    }
    sort(edges.begin(), edges.end());
    edges.resize(unique(edges.begin(), edges.end()) - edges.begin());

    cout << "!";
    for (auto [u, v]: edges) cout << ' ' << u << ' ' << v;
    cout << endl;
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