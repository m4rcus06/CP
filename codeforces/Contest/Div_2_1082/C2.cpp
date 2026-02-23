#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map <int, int> lst;
    deque <int> dq;
    vector <int> par(n, -1);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (lst.find(a[i] - 1) == lst.end() || lst[a[i] - 1] < cur) {
            cur = i;
        } else {
            int p = lst[a[i] - 1];
            while (!dq.empty() && dq.front() <= p) dq.pop_front();
            if (!dq.empty() && a[dq.front()] < a[i]) {
                cur = i;
            }
        }
        if (cur < i) {
            par[i] = lst[a[i] - 1];
        }
        while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        dq.push_back(i);
        lst[a[i]] = i;
    }

    lli ans = 0;
    for (int i = 0; i < n; ++i) {
        //this contribute
        int left = i - par[i];
        ans += (lli) left * (n - i);
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