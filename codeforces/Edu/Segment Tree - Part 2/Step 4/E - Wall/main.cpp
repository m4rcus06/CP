/* https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/E */
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

const int inf = 1e9 + 7;

struct Node {
	int val = 0;
	int lzMn = inf, lzMx = -inf;
};

struct segTree {
	int size;
	vector <Node> Tree;

	void init(int n) {
		Tree.resize(4 * n);
	}

	void push(int id, int lx, int rx) { //idea: IOI 2014 solutions
		if (Tree[id].lzMn != inf) {
			Tree[2 * id].val = min(Tree[2 * id].val, Tree[id].lzMn);
			Tree[2 * id].lzMn = min(Tree[2 * id].lzMn, Tree[id].lzMn);
			Tree[2 * id].lzMx = min(Tree[2 * id].lzMx, Tree[2 * id].lzMn);

			Tree[2 * id + 1].val = min(Tree[2 * id + 1].val, Tree[id].lzMn);
			Tree[2 * id + 1].lzMn = min(Tree[2 * id + 1].lzMn, Tree[id].lzMn);
			Tree[2 * id + 1].lzMx = min(Tree[2 * id + 1].lzMx, Tree[2 * id + 1].lzMn);
		}
		if (Tree[id].lzMx != -inf) {
			Tree[2 * id].val = max(Tree[2 * id].val, Tree[id].lzMx);
			Tree[2 * id].lzMx = max(Tree[2 * id].lzMx, Tree[id].lzMx);
			Tree[2 * id].lzMn = max(Tree[2 * id].lzMn, Tree[2 * id].lzMx);

			Tree[2 * id + 1].val = max(Tree[2 * id + 1].val, Tree[id].lzMx);
			Tree[2 * id + 1].lzMx = max(Tree[2 * id + 1].lzMx, Tree[id].lzMx);
			Tree[2 * id + 1].lzMn = max(Tree[2 * id + 1].lzMn, Tree[2 * id + 1].lzMx);
		}

		Tree[id].lzMn = inf;
		Tree[id].lzMx = -inf;
	}

	void minimize(int id, int lx, int rx, int u, int v, int k) {
		if (lx > v || rx < u) return;
		if (lx >= u && rx <= v) {
			Tree[id].val = min(Tree[id].val, k);
			Tree[id].lzMn = min(Tree[id].lzMn, k);
			Tree[id].lzMx = min(Tree[id].lzMx, Tree[id].lzMn);
			return;
		}

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		minimize(2 * id, lx, mx, u, v, k);
		minimize(2 * id + 1, mx + 1, rx, u, v, k);
	}

	void minimize(int l, int r, int k) {
		++l, ++r;
		minimize(1, 1, size, l, r, k);
	}

	void maximize(int id, int lx, int rx, int u, int v, int k) {
		if (lx > v || rx < u) return;
		if (lx >= u && rx <= v) {
			Tree[id].val = max(Tree[id].val, k);
			Tree[id].lzMx = max(Tree[id].lzMx, k);
			Tree[id].lzMn = max(Tree[id].lzMn, Tree[id].lzMx);
			return;
		}

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		maximize(2 * id, lx, mx, u, v, k);
		maximize(2 * id + 1, mx + 1, rx, u, v, k);
	}

	void maximize(int l, int r, int k) {
		++l, ++r;
		maximize(1, 1, size, l, r, k);
	}

	int query(int id, int lx, int rx, int i) {
		if (lx > i || rx < i) return -1;
		if (lx == rx) return Tree[id].val;

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		int idx = query(2 * id, lx, mx, i);
		if (idx == -1) idx = query(2 * id + 1, mx + 1, rx, i);
		return idx;
	}

	int query(int i) {
		return query(1, 1, size, i);
	}
};

void solve() {
	int n, q;
	cin >> n >> q;

	segTree St;
	St.size = n;
	St.init(n);

	while (q--) {
		int type, l, r, h;
		cin >> type >> l >> r >> h;
		if (type == 1) St.maximize(l, r, h);
		else St.minimize(l, r, h);
	}

	for (int i = 1; i <= n; ++i) {
		cout << St.query(i) << '\n';
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
