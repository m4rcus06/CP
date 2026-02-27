#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const int mod = 998244353;

vector<int> prefix_function(vector <int> s) {
    int n = (int) s.size();
    vector <int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve() {
    int n; cin >> n;
    vector <int> a(n);
    for (auto &x: a) cin >> x;

    vector possible(n + 1, vector <int> (n + 1));
    //possible[i][j] : if reversing [i, j] won't cause overcount
    //which mean there is no prefix in [i, j] that equals to its suffix
    for (int i = 0; i < n; ++i) {
        vector <int> p = prefix_function(a);
        for (int j = i + 1; j < n; ++j) {
            if (p[j - i] == 0) {
                possible[i + 1][j + 1] = 1;
            }
        }
        a.erase(a.begin());
    }

    vector <int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        for (int j = 1; j < i; ++j) {
            if (possible[j][i]) (dp[i] += dp[j - 1]) %= mod;
        }
    }
    cout << dp[n] << '\n';
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