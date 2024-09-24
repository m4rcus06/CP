#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define st first
#define nd second

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct event {
	int t, x, y;
};

bool cmp(const event &a, const event &b) {
	return a.t < b.t;
}

int n, t;
string s;
vector <event> a;

bool valid(int p0, int k) {
	vector <bool> infected(n + 1, false);
	vector <int> cnt(n + 1, 0);
	infected[p0] = true;
	for (int i = 1; i <= t; ++i) {
		if (infected[a[i].x]) cnt[a[i].x]++;
		if (infected[a[i].y]) cnt[a[i].y]++;
		if (cnt[a[i].x] <= k && infected[a[i].x]) infected[a[i].y] = true;
		if (cnt[a[i].y] <= k && infected[a[i].y]) infected[a[i].x] = true;
	}

	for (int i = 1; i <= n; ++i) {
		bool x = s[i - 1] - '0';
		if (infected[i] ^ x) return false;
	}
	return true;
}

void solve() {
	cin >> n >> t >> s;
	a.resize(t + 1, {0, 0, 0});
	for (int i = 1; i <= t; ++i) {
		cin >> a[i].t >> a[i].x >> a[i].y;
	}
	sort(all(a), cmp);

	int p0 = 0, mx_k = -1, mn_k = t;
	for (int i = 1; i <= n; ++i) {
		bool flag = false;
		for (int k = 0; k <= t; ++k) {
			if (valid(i, k)) {
				if (!flag) ++p0;
				mx_k = max(mx_k, k);
				mn_k = min(mn_k, k);
				flag = true;
			}
		}
	}

	cout << p0 << ' ' << mn_k << ' ';
	if (mx_k == t) cout << "Infinity";
	else cout << mx_k;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("tracing.in", "r", stdin);
	freopen("tracing.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
