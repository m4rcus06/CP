/* https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/A */
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

const int mxn = 1e5 + 1;
int n, d;
int a[mxn];
double pre[mxn], mn[mxn];

bool good(double avg) {
	memset(mn, 0, sizeof mn);
	memset(pre, 0, sizeof pre);

	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + (a[i] * 1.0 - avg);
		mn[i] = min(mn[i - 1], pre[i]);
	}

	bool flag = false;
	for (int i = 1; i <= n; ++i) {
		int p = lower_bound(mn, mn + n + 1, pre[i], greater<double>()) - mn;

		if (pre[i] - mn[p] >= 0.0 && i - p >= d) flag = true;
	}

	return flag;
}

void get_max(int &L, int &R, double avg) {
	memset(mn, 0, sizeof mn);
	memset(pre, 0, sizeof pre);

	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + (a[i] * 1.0 - avg);
		mn[i] = min(mn[i - 1], pre[i]);
	}

	for (int i = 1; i <= n; ++i) {
		int p = lower_bound(mn , mn + n + 1, pre[i], greater<double>()) - mn;

		if (pre[i] - mn[p] >= 0 && i - p >= d) {
			if (i - p >= R - L + 1) {
				L = p + 1;
				R = i;
			}
		}
	}
}

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	double l = 0.0, r = 1001.0;
	for (int i = 0; i <= 50; ++i) {
		double mid = (l + r) / 2;

		if (good(mid))
			l = mid;
		else
			r = mid;
	}

	int L = 0, R = 0;
	get_max(L, R, l);
	cout << L << ' ' << R;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
