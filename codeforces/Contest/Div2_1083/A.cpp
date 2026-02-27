#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (auto &x: a) cin >> x;
    
    int p = max_element(a.begin(), a.end()) - a.begin();
    swap(a[p], a[0]);

    for (auto x: a) cout << x << ' ';
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