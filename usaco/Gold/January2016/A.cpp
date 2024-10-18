#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;
 
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int N; cin >> N;
    vector <lli> x(N);
    for (int i = 0; i < N; ++i) {
        int p; cin >> p;
        x[i] = 2LL * p;
    }
    sort(x.begin(), x.end());

    auto LeftMost = [&](int where, lli R) -> int {
        int pos = upper_bound(x.begin(), x.end(), where) - x.begin() - 1;

        lli lowest = where - R;
        int delta = R;
        while (pos >= 0) {
            int i = pos;
            while (i >= 0 && x[i] >= lowest) {
                i--;
            }

            if (i == pos) break;
            pos = i;
            if (delta > 1) delta -= 2;
            lowest = x[pos + 1] - delta;
        }

        return pos;
    };
    
    auto RightMost = [&](int where, lli R) -> int {
        int pos = lower_bound(x.begin(), x.end(), where) - x.begin();

        lli highest = where + R;
        int delta = R;
        while (pos < N) {
            int i = pos;
            while (i < N && x[i] <= highest) {
                i++;
            }

            if (i == pos) break;
            pos = i;

            if(delta > 1) delta -= 2;
            if(delta > 1) highest = x[pos - 1] + delta;
        }

        return pos;
    };

    lli lx = 0, rx = 2LL * (*max_element(x.begin(), x.end()));
    while (rx - lx > 1) {
        int mx = (lx + rx) / 2;

        lli L = x[0], R = *max_element(x.begin(), x.end()) + 1;
        while (R - L > 1) {
            int M = (L + R) / 2;

            if (LeftMost(M, mx) < 0) L = M;
            else R = M;
        }
        
        if (RightMost(L, mx) >= N) rx = mx;
        else lx = mx;
    }

    cout << setprecision(1) << fixed << double(rx) / 2.0 << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else 
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
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

