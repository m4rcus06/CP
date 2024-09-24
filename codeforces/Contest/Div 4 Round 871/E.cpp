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

int n, m;
ll a[1001][1001];
bool vis[1001][1001];

ll calc(int i, int j) {
	if (a[i][j] == 0) {
		vis[i][j] = true;
		return 0;
	}
	if (vis[i][j] || i < 1 || i > n || j < 1 || j > m) return 0;
	vis[i][j] = true;
	return (a[i][j] + calc(i + 1, j) + calc(i, j + 1) + calc(i - 1, j) + calc(i, j - 1));
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) cin >> a[i][j], vis[i][j] = false;
	}

	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!vis[i][j]) res = max(res, calc(i, j));
		}
	}

	cout << res << '\n';
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
