/* https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/G */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

void solve() {
	ll n, c;
	string s;
	cin >> n >> c >> s;

	int len = s.size();
	int a_cnt = 0, b_cnt = 0, res = 0;
	ll rudeness = 0;

	for (int l = 0, r = 0; r < len; ++r) {
		if (s[r] == 'a') a_cnt++; //pre-counting 'a'  to avoid the count of 'ba' substring

		if (s[r] == 'b') {
			b_cnt++;
			rudeness += a_cnt; //'b' can match with any 'a' in the left to create 'ab'
		}

		while (rudeness > c) {
			if (s[l] == 'b') --b_cnt;

			if (s[l] == 'a') {
				rudeness -= b_cnt; //'a' can match with any 'b' in the right to create 'ab'
				--a_cnt;
			}
			++l;
		}
		res = max(res, r - l + 1);
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