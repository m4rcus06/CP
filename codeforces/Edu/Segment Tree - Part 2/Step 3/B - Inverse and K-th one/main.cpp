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
	int sum = 0;
	int lazy = 0;
};

struct segTree {
	int size;
	vector <Node> Tree;

	void init(int n) {
		Tree.resize(4 * n, {0, 0});
	}

	void push(int id, int lx, int rx) {
		if (Tree[id].lazy == 0 || lx == rx) return;

		int mx = (lx + rx) >> 1;

		Tree[2 * id].sum = (mx - lx + 1) - Tree[2 * id].sum;
		Tree[2 * id].lazy ^= 1;
		Tree[2 * id + 1].sum = (rx - mx) - Tree[2 * id + 1].sum;
		Tree[2 * id + 1].lazy ^= 1;

		Tree[id].lazy = 0;
	}

	void update(int id, int lx, int rx, int u, int v) {
		if (lx > v || rx < u) return;
		if (lx >= u && rx <= v) {
			Tree[id].sum = (rx - lx + 1) - Tree[id].sum;
			Tree[id].lazy ^= 1;
			return;
		}

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		update(2 * id, lx, mx, u, v);
		update(2 * id + 1, mx + 1, rx, u, v);

		Tree[id].sum = Tree[2 * id].sum + Tree[2 * id + 1].sum;
	}

	void update(int u, int v) {
		update(1, 1, size, u + 1, v);
	}

	int query(int id, int lx, int rx, int k) {
		if (lx == rx) return lx;

		int mx = (lx + rx) >> 1;
		push(id, lx, rx);

		if (Tree[2 * id].sum >= k) return query(2 * id, lx, mx, k);
		return query(2 * id + 1, mx + 1, rx, k - Tree[2 * id].sum);
	}

	int query(int k) {
		return query(1, 1, size, k + 1) - 1;
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
			cin >> l >> r;
			St.update(l, r);
		}
		else {
			int k; cin >> k;
			cout << St.query(k) << '\n';
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
