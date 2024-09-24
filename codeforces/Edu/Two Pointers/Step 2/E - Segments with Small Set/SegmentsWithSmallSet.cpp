/* https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/E */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	vector <int> a(n + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	vector <int> cnt((int)1e5 + 1, 0);
	ll res = 0, dis = 0;
	for (int l = 1, r = 1; r <= n; ++r) {
		if (!cnt[a[r]]) ++dis;
		cnt[a[r]]++;

		while (dis > k) {
			cnt[a[l]]--;
			if (cnt[a[l]] == 0) dis--;
			l++;
		}
		res += r - l + 1;
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
