/* https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/E */
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

struct Node {
	ll val = 0;
	ll lazy = -1;
};

struct segTree {
	int size;
	vector <Node> Tree;

	void init(int n) {
		Tree.resize(4 * n, {0, 0});
	}

	void push(int id, int lx, int rx) {
		if (lx == rx || Tree[id].lazy == -1) return;

		Tree[2 * id].val = Tree[id].lazy;
		Tree[2 * id].lazy = Tree[id].lazy;

		Tree[2 * id + 1].val = Tree[id].lazy;
		Tree[2 * id + 1].lazy = Tree[id].lazy;

		Tree[id].lazy = -1;
	}

	void update(int id, int lx, int rx, int u, int v, ll k) {
		if (lx > v || rx < u) return;
		if (lx >= u && rx <= v) {
			Tree[id].val = k;
			Tree[id].lazy = k;
			return;
		}

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		update(2 * id, lx, mx, u, v, k);
		update(2 * id + 1, mx + 1, rx, u, v, k);
		Tree[id].val = min(Tree[2 * id].val, Tree[2 * id + 1].val);
	}

	void update(int l, int r, ll k) {
		update(1, 1, size, l + 1, r, k);
	}

	ll query(int id, int lx, int rx, int u, int v) {
		if (lx > v || rx < u) return LLONG_MAX;
		if (lx >= u && rx <= v) return Tree[id].val;

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		ll x1 = query(2 * id, lx, mx, u, v);
		ll x2 = query(2 * id + 1, mx + 1, rx, u, v);

		return min(x1, x2);
	}

	ll query(int l, int r) {
		return query(1, 1, size, l + 1, r);
	}
};

void solve() {
	int n, q;
	cin >> n >> q;

	segTree St;
	St.size = n;
	St.init(n);

	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			int l, r;
			ll v;
			cin >> l >> r >> v;
			St.update(l, r, v);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << St.query(l, r) << '\n';
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

