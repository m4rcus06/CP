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
	vector <vector <int>> a(N, vector <int> (N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			char c; cin >> c;
			a[i][j] = c - 'A';
		}
	}

	vector <vector <bool>> vis(N, vector <bool> (N, false));
	auto BFS = [&] (int x, int y, int u, int v, int st_r, int st_c) -> void {
		queue <pair <int, int>> Q;
		Q.push({st_r, st_c});
		vis[st_r][st_c] = true;


		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			int r1 = cur.first, c1 = cur.second;

			for (int i = 0; i < 4; ++i) {
				int r2 = r1 + dx[i], c2 = c1 + dy[i];
				if (r2 < x || r2 > u || c2 < y || c2 > v) continue;

				if (!vis[r2][c2] && a[r2][c2] == a[st_r][st_c]) {
					vis[r2][c2] = true;
					Q.push({r2, c2});
				}
			}
		}
	};

	vector <array <int, 4>> PCL;
	vector <int> cnt(26, 0);
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			for (int u = x; u < N; ++u) {
				for (int v = y; v < N; ++v) {
					fill(vis.begin(), vis.end(), vector <bool> (N, false));
					fill(cnt.begin(), cnt.end(), 0);

					int differences = 0;
					for (int i = x; i <= u; ++i) {
						for (int j = y; j <= v; ++j) {
							if (vis[i][j] == false) {
								cnt[a[i][j]] += 1;
								BFS(x, y, u, v, i, j);
							}
						}
					}

					bool f = false, s = false;
					for (int i = 0; i < 26; ++i) {
						differences += (cnt[i] > 0);
						if (cnt[i] == 1) f = true;
						if (cnt[i] > 1) s = true;
					}

					if (differences == 2 && f == true && s == true) {
						PCL.push_back({x, y, u, v});
					}
				}
			}
		}
	}

	auto isInsde = [&](int i, int j) -> bool {
		return (PCL[i][0] >= PCL[j][0] && PCL[i][1] >= PCL[j][1] && PCL[i][2] <= PCL[j][2] && PCL[i][3] <= PCL[j][3]);
	};

	vector <int> satisfy(PCL.size(), 1);
	for (int i = 0; i < (int) PCL.size(); ++i) {
		for (int j = 0; j < (int) PCL.size(); ++j) {
			if (i == j) continue;

			if (isInsde(i, j)) satisfy[i] = 0;
		}
	}

	int ans = 0;
	for (int i = 0; i < (int) PCL.size(); ++i) {
		ans += satisfy[i];
	}

	cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
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