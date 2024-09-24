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
vector <string> spt, pln;

bool good(int i) {
	vector <int> cnt(26, 0);
	for (int x = 1; x <= n; ++x) {
		cnt[spt[x][i] - 'A'] = 1;
	}
	for (int x = 1; x <= n; ++x) {
		if (cnt[pln[x][i] - 'A']) return 0;
	}
	return 1;
}

void solve() {
	cin >> n >> m;
	spt.resize(n + 1);
	pln.resize(n + 1);
	for (int i = 1; i <= n; ++i) cin >> spt[i];
	for (int i = 1; i <= n; ++i) cin >> pln[i];

	int res = 0;
	for (int i = 0; i < m; ++i) {
		res += good(i);
	}

	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
