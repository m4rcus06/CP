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

	vector <vector <bool>> vis(N, vector <bool> (N));
	auto BFS = [&] (int x, int y, int u, int v) -> int {
		fill(vis.begin(), vis.end(), vector <bool> (N, false));
		
	};

	int ans = 0;
	for (int x = 0; x < N; ++x) {
		for (int v = 0; v < N; ++v) {
			for (int u = x; u < N; ++u) {
				for (int v = y; v < N; ++v) {
					ans += BFS(x, y, u, v);
				}
			}
		}
	}
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