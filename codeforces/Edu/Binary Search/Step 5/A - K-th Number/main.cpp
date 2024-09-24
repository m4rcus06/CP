/* https://codeforces.com/edu/course/2/lesson/6/5/practice/contest/285084/problem/A */
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

const int N = 101;
ll n, k;
pll a[N];

bool good(ll mid) {
	ll ret = 0;
	for (int i = 1; i <= n; ++i) {
		if (mid > a[i].st) ret += min(a[i].nd + 1, mid) - a[i].st;
	}

	return ret <= k;
}

void solve() {
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i].st >> a[i].nd;
	}

	ll l = -2e9 - 7, r = 2e9 + 7;
	while (r - l > 1) {
		ll mid = (l + r) / 2;

		if (good(mid)) l = mid;
		else r = mid;
	}

	cout << l;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
