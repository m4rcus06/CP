#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </Coding/Library/debug.h>
#else
#define debug(...)
#endif

const int64_t inf = 1e16 + 7;
const int N = 105;
 
int n, t1, t2;
int64_t a[N], b[N], c[N];

bool P(int64_t m) {
    int64_t lx = max(int64_t(1), t1 - m);
    int64_t rx = min(int64_t(t1), t1 + t2 - m - 1);

    int64_t coeff = t1 + t2 - m;
    for (int i = 0; i < n; ++i) {
        int dif = a[i] - b[i];

        if (dif > 0) {
            rx = min(rx, (c[i] - b[i] * coeff) / dif);
        } 
        else if (dif < 0) {
            //basically ceiling stuff
            lx = max(lx, (c[i] - b[i] * coeff + dif + 1) / dif);
        } 
        else {
            if (a[i] * (t1 + t2 - m) > c[i]) return false;
        }
    }
    return lx <= rx;
}

void solve() {
    cin >> n >> t1 >> t2;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int64_t l = -1, r = (t1 + t2 - 2);
    while (r - l > 1) {
        int64_t m = (l + r) / 2;

        if (P(m)) r = m;
        else l = m;
    }

    cout << r << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}