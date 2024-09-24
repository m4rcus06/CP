/* https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/B */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

void solve() {
	ll n, s; cin >> n >> s;

	vector <ll> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	ll sum = 0, res = 0;
	for (ll l = 1, r = 1; r <= n; ++r) {
		sum += a[r];

		while (sum > s) {
			sum -= a[l];
			++l;
		}

		res += (r - l + 1) * (r - l + 2) / 2;
	}

	cout << res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
