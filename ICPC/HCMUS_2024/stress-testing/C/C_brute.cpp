#include <bits/stdc++.h>
using namespace std;

int check(long long x) {
    long long tmp = x;
    while (tmp > 0) {
        long long num = tmp % 10;
        if (num == 0 || (x % num) != 0) return 0;
        tmp /= 10;
    }
    return 1;
}

void solve() {
    long long ans = 0;
    long long l, r;
    cin >> l >> r;
    assert(l <= r);
    for (long long i = l; i <= r; ++i) {
        ans += check(i);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen ("C.in", "r", stdin);
    freopen ("C.out", "w", stdout);

    int tt = 1;
    while(tt--) {
        solve();
    }
    return 0;
}