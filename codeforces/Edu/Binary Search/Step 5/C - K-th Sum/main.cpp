/* https://codeforces.com/edu/course/2/lesson/6/5/practice/contest/285084/problem/C */
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

ll n, k;
int a[N], b[N];

bool good(ll x) {
	ll cnt = 0; //the number of pair (i, j) <= x
	for (int i = 1, j = n; i <= n; ++i) {
		while (a[i] + b[j] > x && j > 0) --j;
		cnt += j;
	}

	return cnt >= k;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	sort(b + 1, b + n + 1);
	sort(a + 1, a + n + 1);

	ll l = 0, r = 2e9 + 7;
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
