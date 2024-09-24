/* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

bool check(double mid, vector <double> &a, int k, int n) {
	ll cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cnt += int(a[i] / mid);
	}

	return cnt >= k;
}

void solve() {
	int n, k; cin >> n >> k;

	vector <double> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	double l = 0, r = 1e9;
	for (int i = 1; i <= n; ++i) r += a[i];

	cout << setprecision(20);
	double eps = 1e-7;
	while (r - l > eps) {
		double mid = (l + r) / 2;

		if (check(mid, a, k, n)) l = mid;
		else r = mid;
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