#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif

namespace std {
 
template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
    static_assert(D >= 1, "Dimension must be positive");
    template <typename... Args>
    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
 
template <typename T>
struct Vec<1, T> : public vector<T> {
    Vec(int n = 0, T val = T()) : std::vector<T>(n, val) {}
};
}

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
 
void solve() {
	int N, K, R; cin >> N >> K >> R;
	set <array <int, 4>> roads;
	for (int i = 0; i < R; ++i) {
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		--x, --y, --u, --v;

		roads.insert({x, y, u, v});
		roads.insert({u, v, x, y});
	}

	Vec <2, bool> cows(N, N, 0);
	for (int i = 0; i < K; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;

		cows[x][y] = true;
	}

	Vec <2, bool> vis(N, N, false);
	auto BFS = [&](int i, int j) -> int {
		vis[i][j] = true;
		queue <pair <int, int>> Q;
		Q.push({i, j});

		int res = 0;
		while (!Q.empty()) {
			auto t = Q.front(); Q.pop();
			int x = t.first, y = t.second;

			res += cows[x][y];

			for (int i = 0; i < 4; ++i) {
				int u = x + dx[i], v = y + dy[i];
				if (u < 0 || u >= N || v < 0 || v >= N) continue;
				if (roads.find({x, y, u, v}) != roads.end()) continue;

				if (!vis[u][v]){
					vis[u][v] = true;
					Q.push({u, v});
				}
			}
		}
		return res;
	};

	vector <int> components;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!vis[i][j] && cows[i][j]) {
				components.push_back(BFS(i, j));
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < (int) components.size(); ++i) {
		for (int j = i + 1; j < (int) components.size(); ++j) {
			ans += components[i] * components[j];
		}
	}

	cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
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