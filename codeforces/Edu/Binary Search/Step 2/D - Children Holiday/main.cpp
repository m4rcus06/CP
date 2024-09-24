/* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

struct node {
	ll t, z, y;
};

ll m, n;
vector <node> a;

ll calc(ll time, ll t, ll z, ll y) {
	ll cycl = t * z + y;
	ll ret = (time / cycl) * z + min(z, (time % cycl) / t);

	return ret;
}

bool good(ll dur) {
	ll ret = 0;

	for (int i = 1; i <= n; ++i) {
		ret += calc(dur, a[i].t, a[i].z, a[i].y);
	}

	return ret >= m;
}

void solve() {
	cin >> m >> n;

	a.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i].t >> a[i].z >> a[i].y;

	ll l = 0, r = 1;
	while (!good(r)) r *= 2;

	while (r - l > 1) {
		ll mid = (l + r) / 2;

		if (good(mid))
			r = mid;
		else
			l = mid;
	}

	if (m == 0) r = 0;
	cout << r << '\n';

	ll total = 0;
	for (int i = 1; i <= n; ++i) {
		ll infl = calc(r, a[i].t, a[i].z, a[i].y);

		if (total <= m)
			cout << min(infl, m - total);
		else
			cout << 0;

		total += infl;
		cout << ' ';
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
