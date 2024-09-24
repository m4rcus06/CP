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

	for (int x = 0; x <= n; ++x) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] > x) ++cnt;
		}
		if (cnt == x) {
			cout << x << '\n';
			return;
		}
	}
	cout << -1 << '\n';
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
