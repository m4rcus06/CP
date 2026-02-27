#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> A(n);
    for (auto &x: A) cin >> x;

    vector <int> B(m);
    for (auto &x: B) cin >> x;

    vector <int> cnt(n + m + 1);
    for (auto x: A) cnt[x]++;
    vector <int> f(n + m + 1);
    for (int i = 1; i <= n + m; ++i) {
        for (int j = i; j <= n + m; j += i) {
            f[j] += cnt[i];
        }
    }

    int alice = 0, bob = 0, both = 0;
    for (auto x: B) {
        if (f[x] == n) alice++;
        else if (f[x] == 0) bob++;
        else both++;
    }

    alice += (both + 1) / 2;
    bob += both / 2;
    cout << (alice > bob ? "Alice" : "Bob") << '\n';
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