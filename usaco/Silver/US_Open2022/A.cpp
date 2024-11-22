#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif

const int mxN = (int) 1e5;

int N;
vector <int> reversed_graph[mxN];
int nxt[mxN], v[mxN];
bool visited[mxN];

void DFS(int u) {
	visited[u] = true;
	for (int v: reversed_graph[u]) {
		if (!visited[v]) DFS(v);
	}
}

int find_minimum(int first) {
	int x = nxt[first], y = nxt[nxt[first]];
	while (x != y) {
		x = nxt[x];
		y = nxt[nxt[y]];
	}

	x = first;
	while (x != y) {
		x = nxt[x];
		y = nxt[y];
	}
	DFS(x);

	int res = v[x];
	while (nxt[x] != y) {
		x = nxt[x];
		res = min(res, v[x]);
	}

	return res;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nxt[i] >> v[i];
		--nxt[i];

		reversed_graph[nxt[i]].push_back(i);
	}

	lli ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += v[i];
		if (!visited[i]) {
			ans -= find_minimum(i);
		}
	}

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