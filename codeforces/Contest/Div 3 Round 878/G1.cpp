#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "LOCAL/debug.h"
#else
#define debug(...) 69420
#endif

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define st first
#define nd second

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1e6 + 7;

int ask(int k, string type) {
	cout << type << " " << k << endl;

	int x; cin >> x;
	return x;
}

void answer(int ans) {
	cout << "! " << ans << endl;
}

int cnt[N];

void solve() {
	int num;
	cin >> num;
	int cur_pos = 1;
	cnt[num] = 1;

	for (int i = 1; i <= 1000; ++i) {
		num = ask(1, "+");
		++cur_pos;

		if (cnt[num]) {
			answer(cur_pos - cnt[num]);
			return;
		}
		cnt[num] = cur_pos;
	}

	while (true) {
		num = ask(1000, "+");
		cur_pos += 1000;

		if (cnt[num]) {
			answer(cur_pos - cnt[num]);
			return;
		}
		cnt[num] = cur_pos;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc = 1;
	while (tc--) {
		solve();
	}

	return 0;
}
