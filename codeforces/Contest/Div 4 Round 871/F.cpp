#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define st first
#define nd second

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 201;

vector <int> adj[N];
int cnt[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		cnt[sz(adj[i])]++;
	}

	int c = cnt[1];

	int x = n - c - 1;
	int y = n / x - 1;


	cout  << x << ' ' << y << '\n';
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i < N; ++i) adj[i].clear();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
