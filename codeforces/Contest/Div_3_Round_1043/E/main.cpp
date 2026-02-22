#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/CP/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater <int>());

    vector <lli> pref_a(n + 1);
    for (int i = 0; i < n; ++i) {
        pref_a[i + 1] = pref_a[i] + a[i];
    }

    vector <int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end(), greater <int>());

    vector <lli> pref_b(m + 1);
    for (int i = 0; i < m; ++i) {
        pref_b[i + 1] = pref_b[i] + b[i];
    }

    vector <pair <int, int>> every;
    for (auto x: a) every.emplace_back(x, 0);
    for (auto x: b) every.emplace_back(x, 1);
    sort(every.begin(), every.end(), greater <pair <int, int>> ());

    vector <lli> sum_all(n + m + 1);
    vector <int> cnt_x(n + m + 1), cnt_y(n + m + 1);
    for (int i = 0; i < n + m; ++i) {
        sum_all[i + 1] = sum_all[i] + every[i].first;
        cnt_x[i + 1] = cnt_x[i] + (every[i].second == 0);
        cnt_y[i + 1] = cnt_y[i] + (every[i].second == 1);
    }

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;

        lli ans = sum_all[z];
        int used_x = cnt_x[z], used_y = cnt_y[z];

        //used_x > x or used_y > y
        //otherwise it will let to z > x + y (contradiction)
        if (used_x > x) {
            ans -= pref_a[used_x] - pref_a[x];
            int delta = used_x - x;
            ans += pref_b[used_y + delta] - pref_b[used_y];
            used_y += delta;
        }
        if (used_y > y) {
            ans -= pref_b[used_y] - pref_b[y];
            int delta = used_y - y;
            ans += pref_a[used_x + delta] - pref_a[used_x];
            used_x += delta;
        }
        
        cout << ans << '\n';
    }
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

