/* https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/C */
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
	int len = 0, cnt = 0;
	bool isLeft = 0, isRight = 0;
	int lazy = -1;
};

struct segTree {
	int size;
	vector <Node> Tree;

	void init(int n) {
		Tree.resize(4 * n);
	}

	void push(int id, int lx, int rx) {
		if (lx == rx) return;

		if (Tree[id].lazy == 0) {
			Tree[2 * id].len = 0;
			Tree[2 * id].cnt = 0;
			Tree[2 * id].lazy = Tree[id].lazy;
			Tree[2 * id].isLeft = Tree[2 * id].isRight = 0;

			Tree[2 * id + 1].len = 0;
			Tree[2 * id + 1].cnt = 0;
			Tree[2 * id + 1].lazy = Tree[id].lazy;
			Tree[2 * id + 1].isLeft = Tree[2 * id + 1].isRight = 0;
		}
		else if (Tree[id].lazy == 1) {
			int mx = (lx + rx) >> 1;
			Tree[2 * id].len = mx - lx + 1;
			Tree[2 * id].cnt = 1;
			Tree[2 * id].lazy = Tree[id].lazy;
			Tree[2 * id].isLeft = Tree[2 * id].isRight = 1;
			Tree[2 * id + 1].len = rx - mx;
			Tree[2 * id + 1].cnt = 1;
			Tree[2 * id + 1].lazy = Tree[id].lazy;
			Tree[2 * id + 1].isLeft = Tree[2 * id + 1].isRight = 1;
		}
		Tree[id].lazy = -1;
	}

	Node compute(int lx, int rx, int k) {
		if (k == 0) return {0, 0, 0, 0, 0};
		return {rx - lx + 1, 1, 1, 1, 1};
	}

	Node merge(Node a, Node b) {
		Node c;
		c.len = a.len + b.len;
		c.cnt = a.cnt + b.cnt - (a.isRight & b.isLeft);
		c.isLeft = a.isLeft;
		c.isRight = b.isRight;

		return c;
	}

	void update(int id, int lx, int rx, int u, int v, int k) {
		if (lx > v || rx < u) return;
		if (lx >= u && rx <= v) {
			Tree[id] = compute(lx, rx, k);
			return;
		}

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		update(2 * id, lx, mx, u, v, k);
		update(2 * id + 1, mx + 1, rx, u, v, k);
		Tree[id] = merge(Tree[2 * id], Tree[2 * id + 1]);
	}

	void update(int l, int r, int k) {
		update(1, 1, size, l, r, k);
	}

	Node query(int id, int lx, int rx, int u, int v) {
		if (lx > v || rx < u) return {0, 0};
		if (lx >= u && rx <= v) return Tree[id];

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		Node x1 = query(2 * id, lx, mx, u, v);
		Node x2 = query(2 * id + 1, mx + 1, rx, u, v);
		return merge(x1, x2);
	}

	pii query() {
		Node ans = query(1, 1, size, 1, size);
		return {ans.cnt, ans.len};
	}
};

const int LIM = 1e6 + 5;
const int ADD = 500001; //make the cords positive

void solve() {
	int q;
	cin >> q;

	segTree St;
	St.size = LIM;
	St.init(LIM);

	while (q--) {
		char type; cin >> type;
		int l, r; cin >> l >> r;
		l += ADD;
		if (type == 'W') St.update(l, l + r - 1, 0);
		else St.update(l, l + r - 1, 1);

		pii ans = St.query();
		cout << ans.st << ' ' << ans.nd << '\n';
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
