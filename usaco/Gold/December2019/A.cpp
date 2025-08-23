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

template <typename T>
using minHeap = priority_queue <T, vector <T>, greater <T>>;

struct Edge {
    int dest, cost, flow_rate;
    Edge(int x = -1, int y = -1, int z = -1) {
        dest = x;
        cost = y;
        flow_rate = z;
    }
};

const int P = int(1e6);

void solve() {
    int n, m;
    cin >> n >> m;
    Tvector <Edge, 2> graph(n);
    vector <int> flows;
    for (int i = 0; i < m; ++i) {
        int u, v, cost, flow_rate;
        cin >> u >> v >> cost >> flow_rate;
        --u, --v;
        flows.push_back(flow_rate);
        graph[u].emplace_back(Edge(v, cost, flow_rate));
        graph[v].emplace_back(Edge(u, cost, flow_rate));
    }
    sort(flows.begin(), flows.end());

    vector <bool> vis(n);
    vector <int> dist(n);
    auto dijkstra = [&](int min_flow) -> int {
        fill(vis.begin(), vis.end(), false);
        fill(dist.begin(), dist.end(), -1);
        minHeap <pair <int, int>> pq;

        dist[0] = 0;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (vis[u] == true) continue;
            vis[u] = true;
            
            for (Edge e: graph[u]) {
                if (e.flow_rate < min_flow) continue;
                int new_dist = dist[u] + e.cost;
                if (dist[e.dest] == -1 || dist[e.dest] > new_dist) {
                    dist[e.dest] = new_dist;
                    pq.emplace(new_dist, e.dest);
                }
            }
        }
        return dist[n - 1];
    };

    int ans = -1;
    for (int f: flows) {
        int path_cost = dijkstra(f);
        if (path_cost == -1) continue;

        double rate = (double) f / (double) path_cost;
        rate *= P;
        ans = max(ans, (int) rate);
    }
    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
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

