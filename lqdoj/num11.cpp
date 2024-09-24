#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "../Library/debug.h"
#else
#define debug(...)
#endif

const int mod = 11;
 
void solve() {
    string N;
    cin >> N;

    int ans = 0;
    for (int i = 0; i < (int) N.size(); ++i) {
        ans = ((ans * 10) + (N[i] - '0')) % mod;
    }
    cout << (ans == 0 ? "YES" : "NO") << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = chrono::high_resolution_clock::now();
#endif
 
    int tt = 1;
    while (tt--) {
        solve();
    }
 
#ifdef LOCAL
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
#endif
 
    return 0;
}

