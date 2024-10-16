#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </Coding/Library/debug.h>
#else
#define debug(...)
#endif

const int64_t inf = 1e18 + 7;

void solve() {
    int N, M; cin >> N >> M;
    vector <pair <int64_t, int64_t>> ranges(M);
    for (int i = 0; i < M; ++i) {
        cin >> ranges[i].first >> ranges[i].second;
    }
    sort(ranges.begin(), ranges.end());

    auto P = [&] (int64_t x) {
        int cnt = 0;
        int64_t pos = -inf;
        for (int i = 0; i < M; ++i) {
            while (max(pos + x, ranges[i].first) <= ranges[i].second) {
                if (cnt >= N) break;

                pos = max(pos + x, ranges[i].first);
                ++cnt;
            }
        }
        return cnt >= N;
    };

    int64_t lx = 1, rx = inf;
    while (rx - lx > 1) {
        int64_t mx = (lx + rx) / 2;

        if (P(mx)) lx = mx;
        else rx = mx;
    }

    cout << lx << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
#ifndef LOCAL
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
#endif

    int tt = 1;
    while(tt--) {
        solve();
    }
    return 0;
}