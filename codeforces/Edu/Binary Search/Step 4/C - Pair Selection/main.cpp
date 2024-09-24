/* https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/C */
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

int n, k;
pii a[N];
double x[N];

bool good(double mid) {
	for (int i = 1; i <= n; ++i) x[i] = 1.0 * a[i].st - a[i].nd * mid;
	sort(x + 1, x + n + 1, greater<double>());

	double ret = 0;
	for (int i = 1; i <= k; ++i) ret += x[i];

	return ret >= 0;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i].st >> a[i].nd;

	double l = 0, r = 1e8;
	for (int i = 0; i <= 50; ++i) {
		double mid = (l + r) / 2;

		if (good(mid)) l = mid;
		else r = mid;
	}
	cout << setprecision(10) << r;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
