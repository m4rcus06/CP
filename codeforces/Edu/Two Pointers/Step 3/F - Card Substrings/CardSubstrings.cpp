/* https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/F */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

vector <int> cnt_n(26, 0), cnt_m(26, 0);

bool good() {
	for (int i = 0; i < 26; ++i) {
		if (cnt_m[i] < cnt_n[i]) return false;
	}

	return true;
}

void add(char x) {
	cnt_n[x - 'a']++;
}

void remove(char x) {
	cnt_n[x - 'a']--;
}

void solve() {
	int n, m;
	string s1, s2;
	cin >> n >> m >> s1 >> s2;

	for (int i = 0; i < m; ++i) cnt_m[s2[i] - 'a']++;

	ll res = 0;

	for (int l = 0, r = 0; r < n; ++r) {
		add(s1[r]);
		while (!good()) {
			remove(s1[l]);
			++l;
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
