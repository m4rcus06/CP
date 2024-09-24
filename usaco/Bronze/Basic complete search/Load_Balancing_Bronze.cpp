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

void solve() {
	int n, b;
	cin >> n >> b;
	vector <pii> a(n + 1, {0, 0});
	for (int i = 1; i <= n; ++i) cin >> a[i].st >> a[i].nd;

	int res = n;
	for (int i = 1; i <= n; ++i) {
		int dx = a[i].st + 1;
		for (int j = 1; j <= n; ++j) {
			int dy = a[j].nd + 1;
			vector <int> cnt(4, 0);
			for (int k = 1; k <= n; ++k) {
				if (a[k].st < dx && a[k].nd < dy) cnt[0]++;
				if (a[k].st < dx && a[k].nd > dy) cnt[1]++;
				if (a[k].st > dx && a[k].nd > dy) cnt[2]++;
				if (a[k].st > dx && a[k].nd < dy) cnt[3]++;
			}
			int mx = *max_element(all(cnt));
			res = min(res, mx);
		}
	}
	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
