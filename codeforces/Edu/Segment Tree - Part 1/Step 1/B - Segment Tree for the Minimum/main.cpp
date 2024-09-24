/* https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B */
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define st first
#define nd second

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1e5 + 1;

int n, m, a[N];
int tree[4 * N];

void build(int id, int l, int r) {
	if (l == r) {
		tree[id] = a[l];
		return;
	}

	int m = (l + r) / 2;
	build(2 * id, l, m);
	build(2 * id + 1, m + 1, r);

	tree[id] = min(tree[2 * id], tree[2 * id + 1]);
}

void update(int id, int l, int r, int pos, int val) {
	if (r < pos || l > pos) return;
	if (l == r) {
		tree[id] = val;
		return;
	}

	int m = (l + r) / 2;
	update(2 * id, l, m, pos, val);
	update(2 * id + 1, m + 1, r, pos, val);

	tree[id] = min(tree[2 * id], tree[2 * id + 1]);
}

int getMin(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return INT_MAX;
	if (l >= u && r <= v) return tree[id];

	int m = (l + r) / 2;
	int x = getMin(2 * id, l, m, u, v);
	int y = getMin(2 * id + 1, m + 1, r, u, v);

	return min(x, y);
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	build(1, 1, n);
	while (m--) {
		int type, x, y;
		cin >> type >> x >> y;
		if (type == 1) update(1, 1, n, x + 1, y);
		else cout << getMin(1, 1, n, x + 1, y) << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
