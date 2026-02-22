#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/CP/Library/debug.h>
#else
#define debug(...) 
#endif

lli fast_pow(lli a, int n) {
    lli res = 1;
    while (n > 0) {
        if (n & 1) res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector <pair <lli, lli>> x;
    int steps = 0;
    int cnt = 0;
    while (n) {
        x.emplace_back(n % 3, cnt);
        steps += n % 3;
        cnt++;
        n /= 3;
    }
    reverse(x.begin(), x.end());

    if (steps > k) {
        cout << -1 << '\n';
        return;
    }

    int left = k - steps;
    for (int i = 0; i + 1 < (int) x.size(); ++i) {
        lli can = min<lli>(x[i].first, left / 2);
        x[i + 1].first += 3 * can;
        x[i].first -= can;
        left -= 2 * can;
    }

    lli ans = 0;
    for (auto [i, j]: x) {
        lli add = fast_pow(3, j + 1) + (lli) j * fast_pow(3, j - 1);
        ans += (lli) i * add;
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

