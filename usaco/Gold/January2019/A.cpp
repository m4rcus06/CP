#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int MOD = (int) 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int fast_pow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        n >>= 1;
    }
    return res;
}

void solve() {
    int N, M, K; cin >> N >> M >> K;
    vector <int> s(N), c(N);
    for (int i = 0; i < N; ++i) {
        cin >> s[i] >> c[i];
        --c[i];
    }
    vector <int> cnt(26, 0);
    for (int i = 0; i < M; ++i) {
        char c; cin >> c;
        cnt[c - 'A'] += 1;
    }

    vector <int> dp(K + 1, 0);
    dp[0] = 1;
    for (int j = 0; j <= K; ++j) {
        for (int i = 0; i < N; ++i) {
            if (j >= s[i]) add(dp[j], dp[j - s[i]]);
        }
    }

    //how many poems ended with word in rhyme class i
    vector <int> ways(N, 0);
    for (int i = 0; i < N; ++i) {
        add(ways[c[i]], dp[K - s[i]]);
    }
    
    vector <int> contribution(26, 0);
    for (int c = 0; c < 26; ++c) {
        if (cnt[c] == 0) {
            contribution[c] = 1;
            continue;
        }
        for (int i = 0; i < N; ++i) {
            add(contribution[c], fast_pow(ways[i], cnt[c]));
        }
    }

    int ans = 1;
    for (int i = 0; i < 26; ++i) {
        ans = 1LL * ans * contribution[i] % MOD;
    }
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
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