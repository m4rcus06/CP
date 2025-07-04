#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/mycp/Library/debug.h>
#else
#define debug(...) 
#endif

const int INF = int(1e9) + 7;

void solve() {
    int N;
    cin >> N;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    bool fail = false;
    int d = 2 * A[0] - A[1];
    if (d % (N + 1) != 0) fail = true;
    
    int y = d / (N + 1);
    if (y < 0) fail = true;
    int x = A[0] - N * y;
    if (x < 0) fail = true;
    for (int i = 0; i < N; ++i) {
        if (x * (i + 1) + y * (N - i) != A[i]) fail = true;
    }

    cout << (fail ? "NO" : "YES") << '\n';
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