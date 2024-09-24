/* https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/D */
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

struct Node {
	int diff;
	int cnt[41];
};

struct SegmentTree {
	int size;
	vector <Node> Tree;
	Node Neutral;

	void empty(Node &a) {
		a.diff = 0;
		for (int i = 0; i <= 40; ++i) a.cnt[i] = 0;
	}

	void init(int n) {
		empty(Neutral);
		Tree.resize(4 * n, Neutral);
	}

	Node makeNode(int a) {
		Node c;
		empty(c);
		c.diff = 1;
		c.cnt[a] = 1;

		return c;
	}

	Node merge(Node a, Node b) {
		Node c;
		empty(c);

		for (int i = 1; i <= 40; ++i) {
			c.cnt[i] = a.cnt[i] + b.cnt[i];
			if (c.cnt[i] > 0) c.diff++;
		}

		return c;
	}

	void build(int id, int l, int r, vector <int> &a) {
		if (l == r) {
			Tree[id] = makeNode(a[l]);
			return;
		}

		int m = (l + r) / 2;
		build(2 * id, l, m, a);
		build(2 * id + 1, m + 1, r, a);

		Tree[id] = merge(Tree[2 * id], Tree[2 * id + 1]);
	}

	void update(int id, int l, int r, int i, int k) {
		if (l > i || r < i) return;
		if (l == r) {
			Tree[id] = makeNode(k);
			return;
		}

		int m = (l + r) / 2;
		update(2 * id, l, m, i, k);
		update(2 * id + 1, m + 1, r, i, k);

		Tree[id] = merge(Tree[2 * id], Tree[2 * id + 1]);
	}

	Node get(int id, int l, int r, int u, int v) {
		if (l > v || r < u) return Neutral;
		if (l >= u && r <= v) return Tree[id];

		int m = (l + r) / 2;
		Node x = get(2 * id, l, m, u, v);
		Node y = get(2 * id + 1, m + 1, r, u, v);

		return merge(x, y);
	}

	void build(vector <int> &a) {
		build(1, 1, size, a);
	}

	void update(int i, int k) {
		update(1, 1, size, i, k);
	}

	Node get(int u, int v) {
		return get(1, 1, size, u, v);
	}
};

const int N = 1e5 + 1;

int n, q;
vector <int> a(N, 0);

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	SegmentTree St;
	St.size = n;
	St.init(n);
	St.build(a);

	while (q--) {
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1) {
			Node ans = St.get(x, y);
			cout << ans.diff << '\n';
		}
		else St.update(x, y);
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
