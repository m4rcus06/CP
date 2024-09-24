/* https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/B */
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
	ll val, lazy;
};

struct segTree {
	int size;
	vector <Node> Tree;

	void init(int n) {
		Tree.resize(4 * n, {0, 0});
	}

	void push(int id, int lx, int rx) {
		if (lx == rx) return;

		int mx = (lx + rx) >> 1;
		Tree[2 * id].val += 1LL * (mx - lx + 1) * Tree[id].lazy;
		Tree[2 * id].lazy += Tree[id].lazy;

		Tree[2 * id + 1].val += 1LL * (rx - mx) * Tree[id].lazy;
		Tree[2 * id + 1].lazy += Tree[id].lazy;

		Tree[id].lazy = 0;
	}

	void update(int id, int lx, int rx, int u, int v, ll k) {
		if (lx > v || rx < u) return;
		if (lx >= u && rx <= v) {
			Tree[id].val += 1LL * (rx - lx + 1) * k;
			Tree[id].lazy += k;
			return;
		}

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		update(2 * id, lx, mx, u, v, k);
		update(2 * id + 1, mx + 1, rx, u, v, k);

		Tree[id].val = Tree[2 * id].val + Tree[2 * id + 1].val;
	}

	void update(int l, int r, ll k) {
		update(1, 1, size, l, r, k);
	}

	ll query(int id, int lx, int rx, int u, int v) {
		if (lx > v || rx < u) return 0;
		if (lx >= u && rx <= v) return Tree[id].val;

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		ll x1 = query(2 * id, lx, mx, u, v);
		ll x2 = query(2 * id + 1, mx + 1, rx, u, v);
		return x1 + x2;
	}

	ll query(int i) {
		return query(1, 1, size, 1, i);
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
			ll l, r, a, d;
			cin >> l >> r >> a >> d;
			St.update(l, l, a);
			St.update(l + 1, r, d);
			St.update(r + 1, r + 1, -a - d * (r - l));
		}
		else {
			int i; cin >> i;
			cout << St.query(i) << '\n';
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
