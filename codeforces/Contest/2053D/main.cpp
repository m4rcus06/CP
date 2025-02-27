#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int MOD = 998244353;

int inv(int x) {
    return x <= 1 ? x : MOD - 1LL * MOD / x * inv(MOD % x) % MOD;
}

void solve() {
    int n, q; cin >> n >> q;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector <int> aa = a, bb = b;
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());

    int ans = 1;
    for (int i = 0; i < n; ++i) {
        ans = 1LL * ans * min(aa[i], bb[i]) % MOD;
    }
    
    cout << ans << ' ';
    while (q--) {
        int t, p;
        cin >> t >> p;
        p--;

        if (t == 1) {
            int idx = upper_bound(aa.begin(), aa.end(), a[p]) - aa.begin() - 1;  
            ans = 1LL * ans * inv(min(aa[idx], bb[idx])) % MOD;
            
            a[p] += 1;
            aa[idx] += 1;
            ans = 1LL * ans * min(aa[idx], bb[idx]) % MOD;
        } else {
            int idx = upper_bound(bb.begin(), bb.end(), b[p]) - bb.begin() - 1;

            ans = 1LL * ans * inv(min(aa[idx], bb[idx])) % MOD;
            
            b[p] += 1;
            bb[idx] += 1;
            ans = 1LL * ans * min(aa[idx], bb[idx]) % MOD;
        }

        cout << ans << ' ';
    }
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