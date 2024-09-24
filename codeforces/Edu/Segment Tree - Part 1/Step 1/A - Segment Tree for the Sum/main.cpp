/* https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A */
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

const int mxn = 1e5 + 1;
int n, m;
ll a[mxn], tree[4 * mxn];

void build_tree(int id, int l, int r) {
	if (l == r) {
		tree[id] = a[l];
		return;
	}

	int mid = (l + r) / 2;
	build_tree(2 * id, l, mid);
	build_tree(2 * id + 1, mid + 1, r);

	tree[id] = tree[2 * id] + tree[2 * id + 1];
}

void update(int id, int l, int r, int i, ll val) {
	if (l > i || r < i) return;

	if (l == r) {
		tree[id] = val;
		return;
	}

	int mid = (l + r) / 2;
	update(2 * id, l, mid, i, val);
	update(2 * id + 1, mid + 1, r, i, val);

	tree[id] = tree[2 * id] + tree[2 * id + 1];
}

ll get_sum(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return 0;

	if (l >= u && r <= v) return tree[id];

	int mid = (l + r) / 2;
	ll g1 = get_sum(2 * id, l, mid, u, v);
	ll g2 = get_sum(2 * id + 1, mid + 1, r, u, v);

	return 1LL * (g1 + g2);
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	build_tree(1, 1, n);
	while (m--) {
		int type;
		cin >> type;

		if (type == 1) {
			ll i, v;
			cin >> i >> v;
			update(1, 1, n, i + 1, v);
		}
		else {
			ll l, r;
			cin >> l >> r;
			cout << get_sum(1, 1, n, l + 1, r) << '\n';
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
