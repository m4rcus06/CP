#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void compress(vector<pair<int, int>> &A) {
    vector<int> nums;
    for (auto &[x, y]: A) {
        nums.push_back(x);
        nums.push_back(y);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (auto &[x, y]: A) {
        x = lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
        y = lower_bound(nums.begin(), nums.end(), y) - nums.begin() + 1;
    }
    nums.clear();
}
 
void solve() {
    int N; cin >> N;
    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    compress(points);

    int sz = 0;
    for (auto &[u, v]: points) {
        sz = max({sz, u, v});
    }

    vector<vector<int>> pref(sz + 1, vector<int>(sz + 1, 0));
    for (auto &[u, v]: points) {
        pref[u][v] = 1;
    }

    for (int i = 1; i <= sz; ++i) {
        for (int j = 1; j <= sz; ++j) {
            pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    auto query = [&] (int x, int y, int u, int v) -> int64_t {
        if (u > sz || v > sz) return 0;
        if (x > u || y > v) return 0;
        return (pref[u][v] - pref[x - 1][v] - pref[u][y - 1] + pref[x - 1][y - 1]);
    };

    int64_t ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            int x, y, u, v;
            x = min(points[i].first, points[j].first);
            y = min(points[i].second, points[j].second);
            u = max(points[i].first, points[j].first);
            v = max(points[i].second, points[j].second);

            ans += (1 + query(x, 1, u, y - 1)) * (1 + query(x, v + 1, u, sz));
        }
    }

    ans += N + 1;
    cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
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

