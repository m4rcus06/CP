/* https://codeforces.com/edu/course/2/lesson/5/3/practice/contest/280799/problem/A */
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

const int NA = 1e9 + 7;

struct Node {
	ll ans = 0;
	ll pre = 0;
	ll suf = 0;
	ll sum = 0;
	ll lazy = NA;
};

struct segTree {
	int size;
	vector <Node> Tree;

	void init(int n) {
		Tree.resize(4 * n);
	}

	Node compute(int id, int lx, int rx, ll k) {
		ll sum = 1LL * (rx - lx + 1) * k;

		if (k > 0) return {sum, sum, sum, sum, k};
		return {0, 0, 0, sum, k};
	}

	void push(int id, int lx, int rx) {
		if (lx == rx) Tree[id].lazy = NA;
		if (Tree[id].lazy == NA) return;

		int mx = (lx + rx) >> 1;
		Tree[2 * id] = compute(2 * id, lx, mx, Tree[id].lazy);
		Tree[2 * id + 1] = compute(2 * id + 1, mx + 1, rx, Tree[id].lazy);
	}

	Node merge(Node a, Node b) {
		return {
			max({a.ans, b.ans, a.suf + b.pre}),
			max(a.pre, a.sum + b.pre),
			max(b.suf, b.sum + a.suf),
			a.sum + b.sum,
			NA,
		};
	}

	void set(int id, int lx, int rx, int u, int v, ll k) {
		if (lx > v || rx < u) return;
		if (lx == rx) {
			Tree[id] = compute(id, lx, rx, k);
			return;
		}

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		set(2 * id, lx, mx, u, v, k);
		set(2 * id + 1, mx + 1, rx, u, v, k);
		Tree[id] = merge(Tree[2 * id], Tree[2 * id + 1]);
	}

	void set(int u, int v, ll k) {
		set(1, 1, size, u + 1, v, k);
	}

	Node query(int id, int lx, int rx, int u, int v) {
		if (lx > v || rx < u) return {0, 0, 0, 0, NA};
		if (lx >= u && rx <= v) return Tree[id];

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		Node x = query(2 * id, lx, mx, u, v);
		Node y = query(2 * id + 1, mx + 1, rx, u, v);
		return merge(x, y);
	}

	ll query(int u, int v) {
		return query(1, 1, size, u + 1, v).ans;
	}
};

void solve() {
	int n, q;
	cin >> n >> q;

	segTree St;
	St.size = n;
	St.init(n);

	while (q--) {
		int l, r, v;
		cin >> l >> r >> v;
		St.set(l, r, 1LL * v);
		cout << St.query(0, n) << '\n';
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

