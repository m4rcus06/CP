/* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/F */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;
string t, p;
vector <int> a;

bool good(int mid) {
	string s = t;
	for (int i = 1; i <= mid; ++i) {
		s[a[i] - 1] = '0';
	}

	int pos = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == p[pos]) pos++;
	}

	return pos == p.size();
}

void solve() {
	cin >> t >> p;

	int n = t.size();
	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	int l = 0, r = n + 1;

	while (r - l > 1) {
		int mid = (l + r) / 2;

		if (!good(mid))
			r = mid;
		else
			l = mid;
	}

	cout << l;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
