#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k < n || k >= 2 * n) {
        cout << "NO" << '\n';
        return;
    }

    if (n == 1) {
        cout << "YES" << '\n';
        cout << 1 << ' ' << 1 << '\n';
        return;
    }

    int needs = k - n;
    vector <int> have, can_use;
    for (int i = n - 1; i >= 0; --i) have.push_back(i);
    vector <int> ans;
    while ((int) ans.size() < 2 * n) {
        if (needs > 0) {
            if (ans.empty()) {
                int x = have.back(); have.pop_back();
                int y = have.back(); have.pop_back();
                ans.push_back(x); ans.push_back(y);
                can_use.push_back(x); can_use.push_back(y);
            } else {
                int x = have.back(); have.pop_back();
                ans.push_back(x); ans.push_back(can_use.back());
                can_use.pop_back(); can_use.push_back(x);
            }
            needs--;
        } else {
            if (!can_use.empty()) {
                ans.push_back(can_use.back());
                can_use.pop_back();
            } else {
                int x = have.back(); have.pop_back();
                ans.push_back(x); ans.push_back(x);
            }
        }
    }

    cout << "YES" << '\n';
    for (auto x: ans) cout << x + 1 << ' ';
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