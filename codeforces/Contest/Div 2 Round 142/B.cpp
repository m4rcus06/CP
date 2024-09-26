#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </Coding/Library/debug.h>
#else
#define debug(...)
#endif

int64_t sqroot(int64_t n) {
    int64_t l = 0, r = 1;
    while (r * r <= n) r *= 2;
    
    while (r - l > 1) {
        int64_t m = (l + r) / 2;

        if (m * m <= n) l = m;
        else r = m;
    }
    return l;
}

bool isPrime (int64_t n) {
    for (int64_t i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return n > 1;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int64_t x; cin >> x;

        int64_t s = sqroot(x);
        cout << ((s * s == x && isPrime(s)) ? "YES" : "NO") << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int tt = 1;
    while(tt--) {
        solve();
    }
    return 0;
}