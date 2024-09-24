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

const int inf = 1e9 + 7;

struct item {
	int l, r, t;
	int cost = -1;

	bool operator < (const item &other) {
		return l < other.l;
	}
};

int n, m;
bool vis[11];
item a[21], b[11];
int res = inf;

bool check() {
	//decrease the temperature
	vector <int> dec_temp(102, 0);
	for (int i = 1; i <= m; ++i) {
		if (vis[i]) {
			for (int j = b[i].l; j <= b[i].r; ++j) dec_temp[j] += b[i].t;
		}
	}

	bool flag = true;
	//check for the condition
	for (int i = 1; i <= n; ++i) {
		for (int j = a[i].l; j <= a[i].r; ++j) {
			if (dec_temp[j] < a[i].t) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}
	return flag;
}

void Try(int x, int cost) {
	if (cost >= res) return;
	if (x > m) {
		if (check()) res = min(res, cost);
		return;
	}

	for (int i = 0; i <= 1; ++i) {
		vis[x] = i;
		Try(x + 1, cost + b[x].cost * i);
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].l >> a[i].r >> a[i].t;
	}

	for (int i = 1; i <= m; ++i) {
		cin >> b[i].l >> b[i].r >> b[i].t >> b[i].cost;
	}
	Try(1, 0);
	cout << res;
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
