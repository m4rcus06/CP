#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;
 
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int x, y; cin >> x >> y;
    string S; cin >> S;
    int N = (int) S.size();
    vector <vector<int>> cnt(N + 1, vector <int> (2, 0));
    for (int i = 0; i < N; ++i) {
        cnt[i + 1] = cnt[i];
        cnt[i + 1][S[i] - '0']++;
    }

    int g = __gcd(x, y);
    x /= g;
    y /= g;

    map <lli, int> mp;
    mp[0] = 1;
    lli ans = 0;
    for (int i = 1; i <= N; ++i) {
        lli v = 1LL * y * cnt[i][0] - x * cnt[i][1];
        if (cnt[i][0] != 0 && cnt[i][1] != 0) {
            ans += mp[v];
        }
        mp[v]++;
    }

    cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif
 
    int tt = 1;
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

