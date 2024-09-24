/* https://codeforces.com/edu/course/2/lesson/5/3/practice/contest/280799/problem/C */
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
	ll lazy = 0;
};

struct segTree {
	int size;
	vector <Node> Tree;

	void init(int n) {
		Tree.resize(4 * n, {0, 0});
	}

	void push(int id, int lx, int rx) {
		Tree[2 * id].val += Tree[id].lazy;
		Tree[2 * id].lazy += Tree[id].lazy;
		Tree[2 * id + 1].val += Tree[id].lazy;
		Tree[2 * id + 1].lazy += Tree[id].lazy;

		Tree[id].lazy = 0;
	}

	void add(int id, int lx, int rx, int u, int v, ll k) {
		if (lx > v || rx < u) return;
		if (lx >= u && rx <= v) {
			Tree[id].val += k;
			Tree[id].lazy += k;
			return;
		}

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		add(2 * id, lx, mx, u, v, k);
		add(2 * id + 1, mx + 1, rx, u, v, k);

		Tree[id].val = max(Tree[2 * id].val, Tree[2 * id + 1].val);// + Tree[id].lazy;
	}

	void add(int l, int r, ll k) {
		add(1, 1, size, l + 1, r, k);
	}

	int find(int id, int lx, int rx, ll x, int len) {
		if (rx < len || Tree[id].val < x) return 0;
		if (lx == rx) return lx;

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		int idx = find(2 * id, lx, mx, x, len);
		if (idx == 0) idx = find(2 * id + 1, mx + 1, rx, x, len);

		return idx;
	}

	int find(ll x, int len) {
		return find(1, 1, size, x, len + 1) - 1;
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
			St.add(l, r, 1LL * v);
		}
		else {
			ll x, len;
			cin >> x >> len;
			cout << St.find(x, len) << '\n';
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
