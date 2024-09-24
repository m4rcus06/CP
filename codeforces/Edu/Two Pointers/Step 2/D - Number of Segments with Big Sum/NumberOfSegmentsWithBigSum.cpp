/* https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/D */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

void solve() {
	int n; ll s;
	cin >> n >> s;
	vector <ll> a(n + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	ll res = 0, sum = 0;
	for (int l = 1, r = 1; r <= n; ++r) {
		sum += a[r];
		while (sum >= s) {
			res += n - r + 1;
			sum -= a[l++];
		}
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
