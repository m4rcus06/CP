/* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

void solve() {
	ll n, w, h; cin >> w >> h >> n;

	ll l = 0, r = 1;

	while ((r / w) * (r / h) <= n) r *= 2;

	while (r - l > 1) {
		ll mid = (l + r) / 2;

		if ((mid / w) * (mid / h) >= n) r = mid;
		else l = mid;
	}

	cout << r;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
