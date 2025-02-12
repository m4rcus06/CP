#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int N; cin >> N;
    vector <int> A(N);
    
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector <pair <int, int>> ops;
    for (int i = 0; i < N; ++i) {
        int j = 0;
        while ((1 << j) < A[i]) j++;
        ops.emplace_back(i + 1, (1 << j) - A[i]);
    }

    cout << ops.size() << '\n';
    for (auto [i, x]: ops) cout << i << ' ' << x << '\n';
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