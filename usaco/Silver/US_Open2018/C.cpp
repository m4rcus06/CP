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

int run_counts = 0;

int n, a[N][N];

Vec <2, bool> vis(N, N, false);
Vec <2, int> region_id(N, N);
int cnt = 0;
int DFS(int i, int j, int c) {
	vis[i][j] = true;
	region_id[i][j] = cnt;
	int res = 1;
	for (int k = 0; k < 4; ++k) {
		int u = i + dx[k], v = j + dy[k];
		if (u < 0 || u >= n || v < 0 || v >= n || a[u][v] != c) continue;
		if (vis[u][v] == false) res += DFS(u, v, c);
	}
	return res;
}

vector <int> region_size, region_color;
Vec <2, int> graph;
map <pair <int, int>, set <int>> seen;
int DFS_region(int u, int c1, int c2) {
	if (seen[{c1, c2}].find(u) != seen[{c1, c2}].end()) return 0;
	++run_counts;
	int res = region_size[u];
	seen[{c1, c2}].insert(u);

	for (int &v: graph[u]) {
		if (region_color[v] == c1 || region_color[v] == c2) {
			res += DFS_region(v, c1, c2);
		}
	}

	return res;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (vis[i][j] == false) {
				region_color.push_back(a[i][j]);
				region_size.push_back(DFS(i, j, a[i][j]));
				cnt += 1;
			}
		}
	}

	int graph_size = cnt;
	graph.resize(graph_size);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i - 1 >= 0 && region_id[i - 1][j] != region_id[i][j]) {
				graph[region_id[i][j]].push_back(region_id[i - 1][j]);
				graph[region_id[i - 1][j]].push_back(region_id[i][j]);
			}
			if (j - 1 >= 0 && region_id[i][j - 1] != region_id[i][j]) {
				graph[region_id[i][j]].push_back(region_id[i][j - 1]);
				graph[region_id[i][j - 1]].push_back(region_id[i][j]);
			}
		}
	}

	for (int i = 0; i < graph_size; ++i) {
		sort(graph[i].begin(), graph[i].end());
		graph[i].resize(unique(graph[i].begin(), graph[i].end()) - graph[i].begin());
	}

	map <pair <int, int>, set <int>> seen;
	int two_teams_sz = 0;
	for (int i = 0; i < graph_size; ++i) {
		for (int &j : graph[i]) {
			pair <int, int> cur = {region_color[i], region_color[j]};
			if (cur.first > cur.second) swap(cur.first, cur.second);
			if (seen[cur].find(i) != seen[cur].end()) continue;

			two_teams_sz = max(two_teams_sz, DFS_region (i, cur.first, cur.second));
		}
	}

	int one_team_sz = *max_element(region_size.begin(), region_size.end());
	cout << one_team_sz << '\n' << two_teams_sz << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);
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