#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

bool isPrime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return x > 1;
}

void solve() {
    int N, M; cin >> N >> M;
    vector <int> primes;
    for (int i = 2; i <= N; ++i) {
        if (isPrime(i)) primes.push_back(i);
    }

    vector <vector <int>> values(primes.size());
    for (int i = 0; i < (int) primes.size(); ++i) {
        int v = primes[i];
        while (v <= N) {
            values[i].push_back(v);
            v *= primes[i];
        }
    }

    auto add = [&](int &a, int b) -> void {
        a += b;
        if (a >= M) a -= M;
    };

    int sz = (int) primes.size();
    vector <vector <int>> dp(2, vector <int> (N + 1, 0));
    fill(dp[0].begin(), dp[0].end(), 1);
    for (int i = 0; i < (int) values.size(); ++i) {
        int cur = i & 1;
        int nxt = cur ^ 1;
        fill(dp[nxt].begin(), dp[nxt].end(), 0);
        for (int j = 0; j <= N; ++j) {
            add(dp[nxt][j], dp[cur][j]);
            for (int v: values[i]) {
                if (j + v <= N) add(dp[nxt][j + v], 1LL * dp[cur][j] * v % M);
            }
        }
    }
    cout << dp[sz & 1][N] << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);
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