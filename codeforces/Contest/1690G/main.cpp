#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...)
#endif

void solve() {
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set <int> S;
    int mn = a[0];
    for (int i = 0; i < n; ++i) {
        if (i == 0) S.insert(i);
        else {
            if (a[i] < mn) {
                S.insert(i);
                mn = a[i];
            }
        }
    }

    while (q--) {
        int k, d; cin >> k >> d;
        --k;
        a[k] -= d;

        while (true) {
            auto itr = S.lower_bound(k);
            if (itr == S.end() || a[*itr] < a[k]) break;
            S.erase(itr);
        }

        S.insert(k);
        auto itr = S.lower_bound(k);
        if (itr != S.begin() && a[*prev(itr)] <= a[k]) S.erase(itr);

        cout << S.size() << ' ';
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