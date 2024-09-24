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

void solve() {
	int n;
	cin >> n;
	vector <int64_t> a(n + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	vector <int64_t> pre(n + 1, 0), suf(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		pre[i] = max(pre[i - 1], a[i] + i);
	}

	suf[n] = a[n] - n;
	for (int i = n - 1; i > 0; --i) {
		suf[i] = max(suf[i + 1], a[i] - i);
	}

	//b[l] + b[m] + b[r] - (r-l) => b[l] + l + b[m] + b[r] - r;
	int64_t res = 0;
	for (int i = 2; i < n; ++i) {
		res = max(res, pre[i - 1] + a[i] + suf[i + 1]);
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
