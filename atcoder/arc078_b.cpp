#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...)
#endif

const int N = (int) 1e5 + 5;

int n;
vector <int> g[N];
vector <int> path;
bool del[N];

bool DFS(int u, int p) {
	for (int v : g[u]) {
		if (v == p) continue;
		path.push_back(v);
		if (DFS(v, u)) {
			return true;
		}
		path.pop_back();
	}
	return u == n - 1;
}

int count_child(int u, int p) {
	int res = 1;
	for (int v : g[u]) {
		if (v == p || del[v]) continue;
		res += count_child(v, u);
	}
	return res;
}

void solve() {
	cin >> n;
	for (int i = 0; i + 1 < n; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;

		g[u].push_back(v);
		g[v].push_back(u);
	}
	DFS(0, 0);

	del[0] = true;
	for (int u : path) {
		del[u] = true;
	}
	int sz = (int) path.size();

	int blacks = count_child(0, 0);
	for (int i = 0; i < sz / 2; ++i) {
		blacks += count_child(path[i], path[i]);
	}

	int white = n - blacks;

	cout << (blacks > white ? "Fennec" : "Snuke") << '\n';
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