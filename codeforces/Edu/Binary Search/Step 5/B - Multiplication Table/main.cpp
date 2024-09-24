/* https://codeforces.com/edu/course/2/lesson/6/5/practice/contest/285084/problem/B */
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

const int N = 1e5 + 1;

int n;
ll k;

bool good(ll x) {
	ll cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cnt += min(1LL * n, 1LL * x / i);
	}

	return cnt >= k;
}

void solve() {
	cin >> n >> k;

	ll l = 0, r = 1LL * n * n;
	while (r - l > 1) {
		ll mid = (l + r) / 2;

		if (good(mid)) r = mid;
		else l = mid;
	}

	cout << r;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
