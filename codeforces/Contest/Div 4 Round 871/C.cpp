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

bool cmp(const pll &a, const pll &b) {
	if (a.nd == b.nd) return a.st < b.st;
	return a.nd > b.nd;
}

void solve() {
	int n; cin >> n;
	map <string, ll> mp;
	for (int i = 1; i <= n; ++i) {
		int x; string s;
		cin >> x >> s;
		if (!mp.count(s)) mp[s] =
			    mp[s] = min(mp[s], 1LL * x);
	}

	ll res = LLONG_MAX;
	if (mp.count("11")) res = min(res, mp["11"]);
	if (mp.count("01") && mp.count("10")) res = min(res, mp["01"] + mp["10"]);

	if (res == LLONG_MAX) res = -1;
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
