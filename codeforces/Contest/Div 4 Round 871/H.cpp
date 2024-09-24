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

const int MOD = 1e9 + 7;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector <int> dp(64, 0);

	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		for (int j = 0; j < 64; ++j) {
			add(dp[j & x], dp[j]);
		}
		add(dp[x], 1);
	}

	int res = 0;
	for (int i = 0; i < 64; ++i) {
		if (__builtin_popcount(i) == k) add(res, dp[i]);
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
