#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int MOD = int(1e9) + 7;

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void normalize(string &s) {
    string res;
    for (auto &c: s) {
        if (c == '1') continue;
        if (c == '0') res.clear();
        res.push_back(0 + (c == '+'));
    }
    s = res;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    normalize(s);
    normalize(t);
    vector dp(s.size() + 1, vector (t.size() + 1, vector <int> (2, 0)));
    dp[0][0][0] = 1;
    int ans = 0;
    for (int i = 0; i <= (int) s.size(); ++i) {
        for (int j = 0; j <= (int) t.size(); ++j) {
            for (int k = 0; k < 2; ++k) {
                if (dp[i][j][k] == 0) continue;
                if (i == (int) s.size() && j == (int) t.size()) add(ans, dp[i][j][k]);
                else {
                    if (j < (int) t.size()) add(dp[i][j + 1][1], dp[i][j][k]);
                    if (k == 0) {
                        if (i < (int) s.size()) add(dp[i + 1][j][0], dp[i][j][k]);
                    }
                    else {
                        if (j > 0 && i < (int) s.size() && s[i] != t[j - 1]) add(dp[i + 1][j][0], dp[i][j][k]);
                    }
                }
            }
        }
    }
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
