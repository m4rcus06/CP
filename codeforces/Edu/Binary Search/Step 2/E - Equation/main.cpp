/* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

double c;
bool good(double x) {
	return (x * x + sqrt(x)) >= c;
}

void solve() {
	cin >> c;

	double l = 0, r = 1e6;

	for (int i = 0; i <= 100; ++i) {
		double mid = (l + r) / 2;

		if (good(mid))
			r = mid;
		else
			l = mid;
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
