#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
	int N, M; cin >> N >> M;
	vector <vector <vector <pair <int, int>>>> g(2, vector <vector <pair <int, int>>> (N));
	for (int i = 0; i < M; ++i) {
		int type, u, v;
		cin >> type >> u >> v;
		--type, --u, --v;

		g[0][u].push_back({type ^ 1, v});
		g[1][u].push_back({type, v});

		g[type ^ 1][v].push_back({0, u});
		g[type][v].push_back({1, u});
	}

	vector <vector <bool>> vis(2, vector <bool> (N, false));
	vector <vector <int>> label(2, vector <int> (N, -1));
	vector <int> total;
	int cnt = -1;

	auto BFS = [&](int t, int u) -> void {
		vis[t][u] = true;
		queue <pair <int, int>> Q;
		Q.push({t, u});

		int res = 0;
		while (!Q.empty()) {
			auto x = Q.front(); Q.pop();
			int _t = x.first, _u = x.second;

			label[_t][_u] = cnt;
			res += (_t == 0);

			for (auto v: g[_t][_u]) {
				if (vis[v.first][v.second] == false) {
					vis[v.first][v.second] = true;
					Q.push(v);
				}
			}
		}

		total.push_back(res);
	};

	for (int i = 0; i < N; ++i) {
		for (int t = 0; t < 2; ++t) {
			if (vis[t][i] == false) {
				++cnt;
				BFS(t, i);
			}
		}

		if (label[0][i] == label[1][i]) {
			cout << -1 << '\n';
			return;
		}
	}

	int ans = 0;
	vector <bool> used(cnt + 1, 0);
	for (int i = 0; i < N; ++i) {
		int F = label[0][i], T = label[1][i];

		if (!used[F] && !used[T]) {
			ans += max(total[F], total[T]);
			used[F] = used[T] = true;
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