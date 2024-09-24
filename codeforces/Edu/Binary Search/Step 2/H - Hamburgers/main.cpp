/* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/H */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;
struct Data {
	ll b, s, c;
};

string s;
Data n, p;
ll cash;

bool good(ll mid) {
	ll B = 0, S = 0, C = 0;
	for (auto it : s) {
		if (it == 'B') ++B;
		if (it == 'S') ++S;
		if (it == 'C') ++C;
	}

	Data need;
	need.b = max(mid * B - n.b, (ll)0);
	need.s = max(mid * S - n.s, (ll)0);
	need.c = max(mid * C - n.c, (ll)0);

	ll price = (B != 0) * need.b * p.b + (S != 0) * need.s * p.s + (C != 0) * need.c * p.c;

	return cash >= price;
}

void solve() {
	cin >> s >> n.b >> n.s >> n.c >> p.b >> p.s >> p.c >> cash;

	ll l = 0, r = 1;
	while (good(r)) r *= 2;

	while (r - l > 1) {
		ll mid = (l + r) / 2;

		if (good(mid))
			l = mid;
		else
			r = mid;
	}

	//if (!good(1)) l = 0;
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
