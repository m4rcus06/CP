#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int n, d; cin >> n >> d;

    vector <int> ans = {1};
    
    if (d % 3 == 0 || n >= 3) ans.push_back(3);
    if (d == 5) ans.push_back(5);
    if (d == 7 || n >= 3) ans.push_back(7);
    if ((d == 3 && n >= 3) || (d == 6 && n >= 3) || (d == 9) || (n >= 6)) ans.push_back(9);

    for (int &v: ans) cout << v << ' ';
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