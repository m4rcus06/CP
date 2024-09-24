#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "LOCAL/debug.h"
#else
#define debug(...) 69420
#endif

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define st first
#define nd second

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
	int n, m;
	cin >> n >> m;
	int r;
	cin >> r;

	bool ok[n + 1][m + 1][r + 1];
	//can we standing still at (n, m) after r shot
	bool dp[n + 1][m + 1][r + 1];
	memset(ok, true, sizeof ok);

	for (int i = 1; i <= r; ++i) {
		int t, d, coord;
		cin >> t >> d >> coord;

		//horizontal shot
		if (d == 1) {
			for (int j = 0; j <= m; ++j) {
				int time_left = t - (coord + j);
				if (time_left >= 0 && time_left <= r) ok[coord][j][time_left] = false;
			}
		}
		else if (d == 2) {
			for (int j = 0; j <= n; ++j) {
				int time_left = t - (coord + j);
				if (time_left >= 0 && time_left <= r) ok[j][coord][time_left] = false;
			}
		}
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; k <= r; ++k) {
				if (i == 0 && j == 0 && k == 0) dp[i][j][k] = true;
				else dp[i][j][k] = false;

				if (ok[i][j][k]) {
					//walk from previous row
					dp[i][j][k] |= (i > 0 && dp[i - 1][j][k]);
					//walk from previous column
					dp[i][j][k] |= (j > 0 && dp[i][j - 1][k]);
					//standing still
					dp[i][j][k] |= (k > 0 && dp[i][j][k - 1]);
				}
			}
		}
	}

	int ans = -1;
	for (int t = r; t >= 0; --t) {
		if (dp[n][m][t]) ans = n + m + t;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}
