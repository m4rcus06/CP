#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

int binpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

void solve() {
    int N, K; cin >> N >> K;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int mx = *max_element(A.begin(), A.end());
    vector <int> bound(mx + 1, 0);
    for (int i = 2; i <= mx; ++i) {
        lli v = i;
        while (v <= 1LL * mx) {
            bound[i] += 1;
            v *= i;
        }
    }

    vector <int> divs(mx + 1, 0);
    for (int i = 2; i <= mx; ++i) {
        if (divs[i] == 0) {
            for (int j = i; j <= mx; j += i) divs[j] = i;
        }
    }

    vector <int> cnt(mx + 1, 0);
    lli ans = 0;
    for (int i = 0; i < N; ++i) {
        int v = A[i];
        int cur = 1, need = 1;

        bool overflow = false;
        while (v > 1) {
            int d = divs[v], cnt = 0;
            while (v % d == 0) {
                ++cnt;
                v /= d;
            }
            int n_pw = cnt % K;
            cur *= binpow(d, n_pw);
            if ((K - n_pw) % K > bound[d]) overflow = true;
            else need *= binpow(d, (K - n_pw) % K);
        }
        if (!overflow && need <= mx) ans += cnt[need];
        cnt[cur] += 1;
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