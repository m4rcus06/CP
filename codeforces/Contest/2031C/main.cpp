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
    vector <int> ans(N + 1);
    if (N % 2 == 1) {
        if (N <= 25) {
            cout << -1 << '\n';
            return;
        }
        else {
            ans[1] = ans[10] = ans[26] = 1;
            ans[23] = ans[27] = 2;
            for (int i = 1, cnt = 2, t = 1; i <= N; ++i) {
                if (ans[i] == 0) {
                    cnt += t;
                    ans[i] = cnt;
                    t ^= 1;
                }
            }
        }
    } else {
        for (int i = 1, cnt = 1; i <= N; i += 2) {
            ans[i] = ans[i + 1] = cnt++;
        }
    }

    for (int i = 1; i <= N; ++i) cout << ans[i] << ' ';
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