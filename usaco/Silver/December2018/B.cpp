#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int N; cin >> N;
    vector<int> a(N), t(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i] >> t[i];
    }

    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {return a[i] < a[j];});
    
    debug(ord);

    int ans = 0;
    int timer = 0;
    set<int> S;
    for (int i = 0; i < N; ++i) {
        if (i > 0 && a[ord[i]] <= timer) {
            S.insert(ord[i]);
        } else {
            while (!S.empty()) {
                if (timer >= a[ord[i]]) {
                    break;
                }

                int cur = *S.begin(); S.erase(S.begin());
                ans = max(ans, timer - a[cur]);
                timer += t[cur];
            }

            if (a[ord[i]] <= timer) {
                S.insert(ord[i]);
            } else {
                timer = a[ord[i]] + t[ord[i]];
            }
        }
    }

    while (!S.empty()) {
        int cur = *S.begin(); S.erase(S.begin());
        ans = max(ans, timer - a[cur]);
        timer += t[cur];
    }


    cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen ("convention2.in", "r", stdin);
    freopen ("convention2.out", "w", stdout);
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

