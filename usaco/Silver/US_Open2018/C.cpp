#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif

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

const int N = 250;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, a[N][N];
Vec <2, bool> vis(N, N, false);

int single_max = 0;
int DFS_single(int i, int j, int c) {
	int res = 1;
	for (int k = 0; k < 4; ++k) {
		int u = i + dx[k], v = j + dy[k];
		if (u < 0 || u >= n || v < 0 || v >= n || a[u][v] != c) continue;
		res += DFS_single(u, v, c);
	}
	return res;
}

int max_reg = 0;
int DFS_reg(int i, int j, int c1, int c2) {
	int res = 1;
	for (int k = 0; k < 4; ++k) {
		int u = i + dx[k], v = j + dy[k];
		if (u < 0 || u >= n || v < 0 || v >= n) continue;
		if (a[u][v] == c1 || a[u][v] == c2) {
			
		}
	}
} 
void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	Vec <1, int> nums;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			nums.push_back(a[i][j]);
		}
	}
	sort(nums.begin(), nums.end());
	nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
	for (int i = 0; i < (int) nums.size(); ++i) {
		for (int j = i + 1; j < (int) nums.size(); ++j) {
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < n; ++y) {
					if (a[x][y] == nums[i] || a[x][y] == nums[j]) {
						DFS_reg(x, y, x, y);
					}
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