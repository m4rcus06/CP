#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/CP/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;

    int m;
    cin >> m;
    string b, c;
    cin >> b >> c;
    
    for (int i = 0; i < m; ++i) {
        if (c[i] == 'V') {
            a = b[i] + a;
        } else {
            a += b[i];
        }
    }
    cout << a << '\n';
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

