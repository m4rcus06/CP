#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/CP/Library/debug.h>
#else
#define debug(...) 
#endif

/*How to use:
  Tvector <int, 2> g(n); //graph
  Tvector <int, 3> f(n, k, 2) = f[n][k][2]
*/
template <class Tp, int D = 1>
struct Tvector : public vector<Tvector<Tp, D - 1>> {
  template <class... Args>
  Tvector(int n = 0, Args... args) : vector<Tvector<Tp, D - 1>>(n, Tvector<Tp, D - 1>(args...)) {}
};
 
template <class Tp>
struct Tvector<Tp, 1> : public vector<Tp> {
  Tvector(int n = 0, Tp val = Tp()) : vector<Tp>(n, val) {}
};

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

template <typename T>
using minHeap = priority_queue <T, vector <T>, greater <T>>;

void solve() {
    int n, move_time;
    cin >> n >> move_time;
    Tvector <int, 2> grid(n, n);
    for (int i = 0; i < n; ++i) {
        for (auto &x: grid[i]) cin >> x;
    }

    auto is_inside = [&](int i, int j) -> bool {
        return (i >= 0 && j >= 0 && i < n && j < n);
    };

    Tvector <int, 3> dist(n, n, 3, -1);
    Tvector <bool, 3> vis(n, n, 3, false);
    minHeap <array <int, 4>> pq;

    pq.push({0, 0, 0, 0});
    dist[0][0][0] = 0;
    while (!pq.empty()) {
        auto [cur_dist, x, y, t] = pq.top(); pq.pop();
        if (vis[x][y][t]) continue;
        vis[x][y][t] = true;

        for (int i = 0; i < 4; ++i) {
            int u = x + dx[i], v = y + dy[i];
            if (!is_inside(u, v)) continue;
            
            int new_t = (t + 1) % 3;
            int new_dist = cur_dist + move_time + (new_t == 0 ? grid[u][v] : 0); 
            if (dist[u][v][new_t] == -1 || dist[u][v][new_t] > new_dist) {
                dist[u][v][new_t] = new_dist;
                pq.push({new_dist, u, v, new_t});
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < 3; ++i) {
        ans = min(ans, dist[n - 1][n - 1][i]);
    }
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w", stdout);
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

