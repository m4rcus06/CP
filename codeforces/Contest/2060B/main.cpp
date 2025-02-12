#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int N, M;
    cin >> N >> M;
    vector <vector <int>> cards(N, vector <int> (M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> cards[i][j];
        }
        sort(cards[i].begin(), cards[i].end());
    }

    vector <int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return cards[i][0] < cards[j][0];
    });

    bool good = true;
    for (int j = 0, mx = - 1; j < M; ++j) {
        if (mx > cards[ord[0]][j]) good = false;
        mx = -1;
        for (int i = 0; i < N; ++i) {
            if (i + 1 < N && cards[ord[i]][j] > cards[ord[i + 1]][j]) good = false;
            mx = max(mx, cards[ord[i]][j]);
        }
    }

    if (!good) cout << -1;
    else for (auto v: ord) cout << v + 1 << ' ';
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