#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/CP/Library/debug.h>
#else
#define debug(...) 
#endif

int sumDigit(lli x) {
    int res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

lli f(lli n) {
    if (n < 10) {
        return n * (n + 1) / 2;
    }
    lli q = n / 10, rem = n % 10;
    return 45LL * q + 10LL * f(q - 1) + rem * (rem + 1) / 2 + (rem + 1) * sumDigit(q);
}

void solve() {
    lli k;
    cin >> k;

    auto count_digit = [&](lli n) {
        lli lft = 1, rig = 10;
        int cnt = 1;
        lli res = 0;
        while (rig <= n) {
            res += (rig - lft) * cnt;
            cnt++;
            lft *= 10;
            rig *= 10;
        }
        res += (n - lft + 1) * cnt;
        return res;
    };

    lli l = 1, r = k + 1;
    while (r - l > 1) {
        lli mid = (l + r) >> 1;
        if (count_digit(mid) <= k) l = mid;
        else r = mid;
    }

    lli ans = f(l);
    k -= count_digit(l);

    string s = to_string(l + 1);
    for (int i = 0; i < k; ++i) ans += (s[i] - '0');
    
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

