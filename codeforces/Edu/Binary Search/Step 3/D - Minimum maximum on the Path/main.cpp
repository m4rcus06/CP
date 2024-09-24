/* https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/D */
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
const int inf = 1e9 + 7;

struct Edge {
	ll v, w;
};

int n, m, d;
ll dp[N], par[N];
vector <Edge> adj[N];

int Traverse(ll mxn) {
	fill_n(dp, N, inf);

	dp[1] = 0;
	for (int u = 1; u <= n; ++u) {
		for (Edge e : adj[u]) {
			int v = e.v;
			ll w = e.w;

			if (w <= mxn) {
				if (dp[v] > dp[u] + 1) {
					dp[v] = dp[u] + 1;
					par[v] = u;
				}
			}
		}
	}
	return dp[n];
}

bool good(ll mid) {
	fill_n(dp, N, inf);
	Traverse(mid);

	return dp[n] <= d;
}

void solve() {
	cin >> n >> m >> d;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back(Edge {v, w});
	}

	ll l = -1, r = inf;
	while (r - l > 1) {
		ll mid = (l + r) / 2;

		if (good(mid)) r = mid;
		else l = mid;
	}

	if (r == inf) {
		cout << -1;
		return;
	}

	Traverse(r);

	vector <int> path;
	for (int i = n; i > 0; i = par[i]) path.push_back(i);
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
