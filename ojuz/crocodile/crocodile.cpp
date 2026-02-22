#include "crocodile.h"
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

const int inf = int(1e9) + 7;

int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]) {
    Tvector <pair <int, int>, 2> graph(N);
    for (int i = 0; i < M; ++i) {
        int u = R[i][0], v = R[i][1];
        graph[u].emplace_back(v, L[i]);
        graph[v].emplace_back(u, L[i]);
    }

    priority_queue <pair <lli, int>> Q;
    Tvector <int, 2> dist(N, 2, inf);
    for (int i = 0; i < K; ++i) {
        Q.emplace(0, P[i]);
        dist[P[i]][0] = dist[P[i]][1] = 0;
    }

    while (!Q.empty()) {
        auto [d, u] = Q.top(); Q.pop();
        d = -d;
        if (d > dist[u][1]) continue;

        for (auto [v, w]: graph[u]) {
            int nxt_dist = d + w;
            if (dist[v][0] > nxt_dist) {
                if (dist[v][0] < dist[v][1]) {
                    dist[v][1] = dist[v][0];
                    Q.emplace(-dist[v][1], v);
                }
                dist[v][0] = nxt_dist;
            } else if (dist[v][1] > nxt_dist) {
                dist[v][1] = nxt_dist;
                Q.emplace(-dist[v][1], v);
            }
        }
    }
    return dist[0][1];
}
