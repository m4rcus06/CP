/* https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

struct Data {
	int x, v;
};

int n;
vector <Data> a;

bool good(double mid) {
	double l = -1e9, r = 1e9;

	for (int i = 1; i <= n; ++i) {
		l = max(l, 1.0 * a[i].x - mid * a[i].v);
		r = min(r, 1.0 * a[i].x + mid * a[i].v);
	}

	return l <= r;
}

void solve() {
	cin >> n;
	a.resize(n + 1);

	for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].v;

	double l = 0, r = 1.0;
	while (!good(r)) r *= 2;

	for (int i = 1; i <= 80; ++i) {
		double mid = (l + r) / 2;

		if (good(mid)) r = mid;
		else l = mid;
	}

	cout << setprecision(20) << r;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
