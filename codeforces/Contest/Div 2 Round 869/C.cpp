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

void solve() {
	int n, q;
	cin >> n >> q;
	vector <int> a(n + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	vector <int> pre(n + 1, 0);
	for (int i = 2; i < n; ++i) {
		pre[i] = pre[i - 1] + (a[i] <= a[i - 1] && a[i + 1] <= a[i]);
	}

	// for (int i = 1; i <= n; ++i) cout << pre[i] << ' ';

	while (q--) {
		int lx, rx;
		cin >> lx >> rx;
		int res = 2;
		if (lx == rx) res = 1;
		else res = max(res, (rx - lx + 1) - (pre[rx - 1] - pre[lx]));
		cout << res << '\n';
	}

}

/*
	taking rx-1 since rx can be the special index where a[rx-1] <= a[rx] <= a[rx+1] (we can take a[rx-1] and a[rx] so we only subtract when the segment contain a[rx+1]);
	same for lx, lx can be the special index where a[lx-1] <= a[lx] <= a[lx+1] (only subtract when the segment contain a[lx], if the segment contain three of them, we will not substract);
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
