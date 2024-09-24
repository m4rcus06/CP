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
	vector <int> a(n + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	int res = 0;
	for (int i = 1; i <= n / 2; ++i) {
		res = __gcd(res, abs(a[i] - a[n - i + 1]));
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
