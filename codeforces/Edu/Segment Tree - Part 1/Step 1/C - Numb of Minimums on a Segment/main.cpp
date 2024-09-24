/* https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C */
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
pii tree[4 * N];

void build(int id, int l, int r) {
	if (l == r) {
		tree[id].st = a[l];
		tree[id].nd = 1;
		return;
	}

	int m = (l + r) / 2;
	build(2 * id, l, m);
	build(2 * id + 1, m + 1, r);

	tree[id].st = min(tree[2 * id].st, tree[2 * id + 1].st);

	pii x = tree[2 * id], y = tree[2 * id + 1];

	if (x.st > y.st) tree[id].nd = y.nd;
	else if (x.st < y.st) tree[id].nd = x.nd;
	else tree[id].nd = x.nd + y.nd;
}

void update(int id, int l, int r, int pos, int val) {
	if (r < pos || l > pos) return;
	if (l == r) {
		tree[id].st = val;
		tree[id].nd = 1;
		return;
	}

	int m = (l + r) / 2;
	update(2 * id, l, m, pos, val);
	update(2 * id + 1, m + 1, r, pos, val);

	tree[id].st = min(tree[2 * id].st, tree[2 * id + 1].st);

	pii x = tree[2 * id], y = tree[2 * id + 1];

	if (x.st > y.st) tree[id].nd = y.nd;
	else if (x.st < y.st) tree[id].nd = x.nd;
	else tree[id].nd = x.nd + y.nd;
}

pii getMin(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return {INT_MAX, -1};
	if (l >= u && r <= v) return tree[id];

	int m = (l + r) / 2;
	pii x = getMin(2 * id, l, m, u, v);
	pii y = getMin(2 * id + 1, m + 1, r, u, v);

	if (x.st < y.st) return x;
	else if (x.st == y.st) return make_pair(x.st, x.nd + y.nd);
	else return y;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	build(1, 1, n);
	while (m--) {
		int type, x, y;
		cin >> type >> x >> y;
		if (type == 1) update(1, 1, n, x + 1, y);
		else {
			pii ans = getMin(1, 1, n, x + 1, y);
			cout << ans.st << ' ' << ans.nd << '\n';
		}
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
