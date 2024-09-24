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
	ll s;
	cin >> n >> s;
	vector <ll> a(n + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	vector <ll> b(n + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> b[i];

	ll w = 0, v = 0;
	ll res = 0;
	for (int l = 1, r = 1; r <= n; ++r) {
		w += a[r];
		v += b[r];
		while (w > s) {
			w -= a[l];
			v -= b[l];
			l++;
		}
		res = max(res, v);
	}
	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
