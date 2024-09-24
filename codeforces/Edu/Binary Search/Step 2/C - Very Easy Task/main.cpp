/* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;


bool good(int mid, int x, int y, int n) {
	return n <= mid / x + mid / y;
}

void solve() {
	ll n, x, y;
	cin >> n >> x >> y;

	ll res = min(x, y);
	n -= 1;

	ll l = 0, r = n * max(x, y);

	while (r - l > 1) {
		int mid = (r + l) / 2;
		if (good(mid, x, y, n)) r = mid;
		else l = mid;
	}

	cout << r + res;

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
