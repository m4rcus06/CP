/* https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/C */
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
	int val = 0;
	int lazy = 0;
};

struct segTree {
	int size;
	vector <Node> Tree;

	void init(int n) {
		Tree.resize(4 * n, {0, 0});
	}

	void update(int id, int lx, int rx, int u, int v, int k) {
		if (lx > v || rx < u) return;
		if (lx >= u && rx <= v) {
			Tree[id].val |= k;
			Tree[id].lazy |= k;
			return;
		}

		int mx = (lx + rx) >> 1;
		update(2 * id, lx, mx, u, v, k);
		update(2 * id + 1, mx + 1, rx, u, v, k);
		Tree[id].val = (Tree[2 * id].val & Tree[2 * id + 1].val) | Tree[id].lazy;
	}

	void update(int l, int r, int k) {
		update(1, 1, size, l + 1, r, k);
	}

	int query(int id, int lx, int rx, int u, int v) {
		if (lx > v || rx < u) return -1;
		if (lx >= u && rx <= v) return Tree[id].val;

		int mx = (lx + rx) >> 1;
		int x1 = query(2 * id, lx, mx, u, v);
		int x2 = query(2 * id + 1, mx + 1, rx, u, v);

		int ret;
		if (x1 == -1) ret = x2;
		else if (x2 == -1) ret = x1;
		else ret = x1 & x2;
		return ret | Tree[id].lazy;
	}

	int query(int l, int r) {
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
			int l, r, v;
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

