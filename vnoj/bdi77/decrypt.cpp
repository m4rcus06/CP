#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int n, m; cin >> n >> m;
    string W, S; cin >> W >> S;

    lli ans = 0;
    vector <int> cnt_S(312, 0), cnt_W(312, 0);
    for (int i = 0; i < n; ++i) {
        cnt_W[W[i]] += 1;
    }

    int need = 0;
    for (int i = 0; i < (int) cnt_W.size(); ++i) {
        need += (cnt_W[i] > 0);
    }

    int matches = 0;
    for (int l = 0, r = 0; r < m; ++r) {
        cnt_S[S[r]] += 1;
        if (cnt_S[S[r]] == cnt_W[S[r]]) matches += 1;
        else if (cnt_S[S[r]] == cnt_W[S[r]] + 1) matches -= 1;

        while (cnt_S[S[r]] > cnt_W[S[r]]) {
            cnt_S[S[l]] -= 1;
            if (cnt_S[S[l]] == cnt_W[S[l]]) matches += 1;
            else if(cnt_S[S[l]] + 1 == cnt_W[S[l]]) matches -= 1;
            l++;
        }

        if (matches == need) ans++;
    }
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("DECRYPT.INP", "r", stdin);
    freopen("DECRYPT.OUT", "w", stdout);
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