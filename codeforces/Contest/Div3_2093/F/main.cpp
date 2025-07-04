#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/mycp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int N, M;
    cin >> N >> M;

    vector <string> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    vector <vector <string>> networks(M, vector <string> (N));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j) cin >> networks[i][j];
    
    bool fail = false;
    for (int i = 0; i < N; ++i) {
        bool col_found = false;

        for (int j = 0; j < M; ++j) {
            if (A[i] == networks[j][i]) col_found = true;
        }
    
        if (!col_found) fail = true;
    }

    
    if (fail) {
        cout << -1 << '\n';
        return;
    }
    
    int max_matches = 0;
    for (int i = 0; i < M; ++i) {
        int cur_matches = 0;

        for (int j = 0; j < N; ++j)
            cur_matches += (A[j] == networks[i][j]);

        max_matches = max(max_matches, cur_matches);
    }

    int ans = N + (N - max_matches) * 2;

    cout << ans << '\n';
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