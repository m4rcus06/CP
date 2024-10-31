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
	Vec <2, set <pair <int, int>>> roads(N, N);
	for (int i = 0; i < R; ++i) {
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		--x, --y, --u, --v;

		roads[x][y].insert({u, v});
		roads[u][v].insert({x, y});
	}

	Vec <3, int> state(N, N, 2, 0);
	auto BFS = [&](int i, int j) -> void{
		queue <array <int, 3>> Q;
		Q.push({i, j, 0});

		while (!Q.empty()) {
			auto t = Q.front(); Q.pop();
			int x = t[0], y = t[1], w = t[2];

			for (auto &itr : roads[x][y]) {
				int u = itr.first, v = itr.second;

				if (state[u][v][1] == 0) {
					state[u][v][1] = 1;
					Q.push({u, v, 1});
				}
			}

			for (int k = 0; k < 4; ++k) {
				int u = x + dx[k], v = y + dy[k];

				if (u < 0 || u >= N || v < 0 || v >= N) continue;
				if (roads[x][y].find({u, v}) != roads[x][y].end()) continue;

				if (state[u][v][w] == 0) {
					state[u][v][w] = 1;
					Q.push({u, v, w});
				}
			}
		}
	};

	vector <pair <int, int>> cows(K);
	for (int i = 0; i < K; ++i) {
		cin >> cows[i].first >> cows[i].second;
		--cows[i].first, --cows[i].second;
	}

	int ans = 0;
	for (int i = 0; i < K; ++i) {
		BFS(cows[i].first, cows[i].second);

		for (int j = i + 1; j < K; ++j) {
			int x = cows[j].first, y = cows[j].second;

			if (state[x][y][0] == 0 && state[x][y][1] == 1) {
				ans += 1;
			}
		}

		fill(state.begin(), state.end(), Vec <2, int> (N, 2, 0));
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