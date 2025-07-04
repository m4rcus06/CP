#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/mycp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int N, xL, yL, xB, yB;
    cin >> N >> xL >> yL >> xB >> yB;

    vector <int> x(N), y(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }

    map <int, vector <int>> at_x, at_y;
    at_x[xL].push_back(N);
    at_y[yL].push_back(N);

    for (int i = 0; i < N; ++i) {
        at_x[x[i]].push_back(i);
        at_y[y[i]].push_back(i);
    }

    vector visited(2, vector <bool> (N + 1, false));
    visited[0][N] = visited[1][N] = true;
    queue <array <int, 4>> myqueue;
    myqueue.push({xL, yL, 0, 0});
    myqueue.push({xL, yL, 1, 0});

    while(!myqueue.empty()) {
        auto [cur_x, cur_y, dir, d] = myqueue.front(); myqueue.pop();
        debug(cur_x, cur_y, dir, d);
        if (dir == 0 && cur_y == yB) {
            cout << d << '\n';
            return;
        }

        if (dir == 1 && cur_x == xB) {
            cout << d << '\n';
            return;
        }

        if (dir == 0) {
            for (auto idX: at_y[cur_y]) {
                int next_x = x[idX];
                if (!visited[dir ^ 1][idX]) {
                    visited[dir ^ 1][idX] = true;
                    myqueue.push({next_x, cur_y, dir ^ 1, d + 1});
                }
            }
        }

        if (dir == 1) {
            for (auto idY: at_x[cur_x]) {
                int next_y = y[idY];
                if (!visited[dir ^ 1][idY]) {
                    visited[dir ^ 1][idY] = true;
                    myqueue.push({cur_x, next_y, dir ^ 1, d + 1});
                }
            }
        }
    }

    cout << -1 << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
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