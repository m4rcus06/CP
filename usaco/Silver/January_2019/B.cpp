#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
 
void solve() {
	int N; cin >> N;
	vector <vector <int>> a(N, vector <int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			char c; cin >> c;
			a[i][j] = (c == '#');
		}
	}

	int S = 0, P = 0;
	vector <vector <bool>> vis(N, vector <bool> (N, false));
	auto BFS = [&](int i, int j) -> void {	
		queue <pair <int, int>> Q;
		Q.push({i, j});

		S = P = 0;
		while (!Q.empty()) {
			auto t = Q.front(); Q.pop();
			int x = t.first, y = t.second;

			if (a[x][y] == 0) {
				++P;
				continue;
			}

			if (vis[x][y] == true) continue;
			vis[x][y] = true;


			if (a[x][y] == 1) {
				++S;
			}

			for (int k = 0; k < 4; ++k) {
				int u = x + dx[k], v = y + dy[k];
				if (u < 0 || u >= N || v < 0 || v >= N) ++P;
				else {
					Q.push({u, v});
				}
			}
		}
	};

	int ans_S = -1, ans_P = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (vis[i][j] == false && a[i][j] == 1) {
				BFS(i, j);

				if (S == ans_S) ans_P = min(ans_P, P);
				else if (S > ans_S) {
					ans_S = S;
					ans_P = P;
				}
			}
		}
	}

	cout << ans_S << ' ' << ans_P << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
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