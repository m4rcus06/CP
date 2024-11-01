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

const int MAX_SIZE = 250;

int N, B;
int f[MAX_SIZE], s[MAX_SIZE], d[MAX_SIZE];
bool vis[MAX_SIZE][MAX_SIZE];

int ans = 1e9 + 7;
void DFS(int i, int j) {
	if (j >= B) return;
	if (i == N - 1) {
		ans = min(ans, j);
		return;
	}

	if (vis[i][j] == true) return;
	vis[i][j] = true;


	DFS(i, j + 1);
	if (f[i] > s[j]) return;

	for (int k = i + 1; k <= min(N - 1, i + d[j]); ++k) {
		if (f[k] <= s[j]) DFS(k, j);
	}
}
 
void solve() {
	cin >> N >> B;
	for (int i = 0; i < N; ++i) {
		cin >> f[i];
	}

	for (int i = 0; i < B; ++i) {
		cin >> s[i] >> d[i];
	}
	DFS(0, 0);

	cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
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