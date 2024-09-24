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

struct SegmentTree {
	int size;
	vector <int> Tree;

	void init(int n) {
		Tree.resize(4 * n, 0);
	}

	void assign(int &x, int y) { //assign y to x
		if (y == -1) return;
		x = y;
	}

	void propagate(int id, int lx, int rx) {
		if (lx == rx) return;
		assign(Tree[2 * id], Tree[id]);
		assign(Tree[2 * id + 1], Tree[id]);
		Tree[id] = -1;
	}

	void set(int id, int lx, int rx, int u, int v, ll k) {
		if (lx > v || rx < u) return;
		if (lx >= u && rx <= v) {
			assign(Tree[id], k);
			return;
		}

		propagate(id, lx, rx);
		int mx = (lx + rx) >> 1;
		set(2 * id, lx, mx, u, v, k);
		set(2 * id + 1, mx + 1, rx, u, v, k);
	}

	void set(int l, int r, ll k) {
		set(1, 1, size, l + 1, r, k);
	}

	ll query(int id, int lx, int rx, int i) {
		if (lx > i || rx < i) return -1;
		if (lx == rx) return Tree[id];

		int mx = (lx + rx) >> 1;
		int x = query(2 * id, lx, mx, i);
		int y = query(2 * id + 1, mx + 1, rx, i);

		if (x == -1) {
			assign(y, Tree[id]);
			return y;
		}
		assign(x, Tree[id]);
		return x;
	}

	ll query(int i) {
		return query(1, 1, size, i + 1);
	}
};

void solve() {
	int n, q;
	cin >> n >> q;

	SegmentTree St;
	St.size = n;
	St.init(n);

	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r, k;
			cin >> l >> r >> k;
			St.set(l, r, 1LL * k);
		}
		else {
			int idx;
			cin >> idx;
			cout << St.query(idx) << '\n';
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