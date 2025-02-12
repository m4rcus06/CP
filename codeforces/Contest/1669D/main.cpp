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
    string S; cin >> S;
    S.push_back('W');
    N += 1;

    bool ok = true;
    for (int i = 0, red = 0, blue = 0; i < N; ++i) {
        if (S[i] == 'W') {
            if (red + blue == 1) ok = false;
            red = blue = 0;
        }
        if (S[i] == 'B') blue = 1;
        if (S[i] == 'R') red = 1;
    }
    cout << (ok ? "YES" : "NO") << '\n';
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