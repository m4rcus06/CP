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
	string s; cin >> s;
	string cmp = "codeforces";

	int res = 0;
	for (int i = 0; i < sz(s); ++i) {
		res += (s[i] != cmp[i]);
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
