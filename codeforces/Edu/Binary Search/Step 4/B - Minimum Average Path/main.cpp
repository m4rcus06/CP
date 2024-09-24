/* https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/B */
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define st first
#define nd second

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1e5 + 1;
const double inf = 1e18;

struct Edge {
	int v, w;
};

int n, m;
int par[N];
double dp[N]; //minimum cost of the path 1..N
vector <Edge> adj[N];

bool good(double m) {
	fill_n(dp, N + 1, inf);

	dp[1] = 0;
	for (int u = 1; u <= n; ++u) {
		for (auto e : adj[u]) {
			int v = e.v;
			int w = e.w;
			dp[v] = min(dp[v], (double) dp[u] + (1.0 * w) - m);
		}
	}

	return dp[n] <= 0.0;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(Edge {v, w});
	}

	double l = 0, r = 1e3;
	for (int i = 0; i <= 80; ++i) {
		double mid = (l + r) / 2;

		if (good(mid))
			r = mid;
		else
			l = mid;
	}

	fill_n(dp, N + 1, inf);
	dp[1] = 0;
	for (int u = 1; u <= n; ++u) {
		for (auto e : adj[u]) {
			int v = e.v;
			int w = e.w;

			if (dp[v] > dp[u] + (1.0 * w) - r) {
				par[v] = u;
				dp[v] = (double) dp[u] + (1.0 * w) - r;
			}
		}
	}

	vector <int> path;
	for (int i = n; i > 0; i = par[i]) {
		path.push_back(i);
	}

	reverse(all(path));
	cout << sz(path) - 1 << '\n';
	for (auto it : path) cout << it << ' ';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
