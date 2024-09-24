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

bool dp(int n, int m) {
	if (n == m) return true;
	if (n % 3 != 0 || n < m) return false;

	return (dp(n / 3 * 2, m) || dp(n / 3, m));
}

void solve() {
	int n, m;
	cin >> n >> m;
	cout << (dp(n, m) ? "YES" : "NO") << '\n';
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
