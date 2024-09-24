/* https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

void solve() {
	int n, q; cin >> n >> q;

	vector <ll> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	while (q--) {
		ll x; cin >> x;
		int p = lower_bound(a.begin(), a.end(), x) - a.begin() + 1;

		cout << p << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
