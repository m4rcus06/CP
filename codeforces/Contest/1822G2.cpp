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

const int N = 2e5 + 1;

int n;
ll a[N];
map <ll, ll> mp;

ll get(ll x, ll LIM) {
	if (!mp.count(x) || x > LIM) return 0;
	return mp[x];
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mp[a[i]]++;
	}
	ll LIM = *max_element(a + 1, a + n + 1);

	ll res = 0;
	for (auto it : mp) {
		int val = it.st, cnt = it.nd;
		if (cnt >= 3) res += 1LL * cnt * (cnt - 1) * (cnt - 2);
		//(x, x, x) -> 3Px

		for (int b = 2; b * b <= val && b * val <= LIM; ++b) { //b * val <= LIM : not exceeding max(a[1..n])
			if (val % b == 0) {
				int x1 = b, x2 = val / b;

				res += 1LL * get(val / x1, LIM) * cnt * get(1LL * val * x1, LIM);
				if (x1 != x2) res += 1LL * get(val / x2, LIM) * cnt * get(1LL * val * x2, LIM);
			}
		}
		if (val != 1) res += 1LL * get(1, LIM) * cnt * get(1LL * val * val, LIM);
		//(1, x, x)
	}

	cout << res << '\n';
	mp.clear();
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
