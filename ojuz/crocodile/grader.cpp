#include "crocodile.h"
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 50000
#define MAX_M 10000000

static int N, M;
static int R[MAX_M][2];
static int L[MAX_M];
static int K;
static int P[MAX_N];
static int solution;

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
            debug(u, v, d, w, dist[v]);
        }
    }
    return dist[0][1];
}

inline 
void my_assert(int e) {if (!e) abort();}

void read_input()
{
  int i;
  my_assert(3==scanf("%d %d %d",&N,&M,&K));
  for(i=0; i<M; i++)
    my_assert(3==scanf("%d %d %d",&R[i][0],&R[i][1],&L[i]));
  for(i=0; i<K; i++)
    my_assert(1==scanf("%d",&P[i]));
  my_assert(1==scanf("%d",&solution));
}

int main()
{
  int ans;
  read_input();
  ans = travel_plan(N,M,R,L,K,P);
  if(ans==solution)
    printf("Correct.\n");
  else
    printf("Incorrect. Returned %d, Expected %d.\n",ans,solution);

  return 0;
}
