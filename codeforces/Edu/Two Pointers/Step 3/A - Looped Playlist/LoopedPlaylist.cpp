/* https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/A */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

void solve() {
	ll n, p; cin >> n >> p;

	vector <ll> a(n + 1);
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	ll res = (p / sum) * n;
	p %= sum;

	ll mn = LLONG_MAX, start = 0;

	for (int i = 1; i <= n; ++i) {
		ll mood = 0, cnt = 0;

		for (int j = i; mood < p; ++j) {
			if (j > n) j -= n;

			mood += a[j];
			++cnt;
		}

		if (mn > cnt) {
			mn = cnt;
			start = i;
		}
	}

	cout << start << ' ' << res + mn;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
