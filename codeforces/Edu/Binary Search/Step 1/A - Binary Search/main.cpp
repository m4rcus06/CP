/* https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

void solve() {
	int n, q; cin >> n >> q;

	vector <int> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	while (q--) {
		int x; cin >> x;

		bool ok = binary_search(a.begin() + 1, a.end(), x);
		if (ok) cout << "YES";
		else cout << "NO";
		cout << '\n';

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
