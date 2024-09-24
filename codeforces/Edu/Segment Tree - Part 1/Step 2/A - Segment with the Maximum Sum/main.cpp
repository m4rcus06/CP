/* https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A */
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

const int N = 1e5 + 1;

struct Node {
	ll seg, pre, suf, sum;
};

struct SegmentTree {
	int size;
	vector <Node> Tree;
	Node Neutral = {0, 0, 0, 0};

	void init(int n) {
		Tree.resize(4 * n, Neutral);
	}

	Node makeNode(ll x) {
		if (x > 0) return {x, x, x, x};
		return {0, 0, 0, x};
	}

	Node merge(Node a, Node b) {
		return {
			max({a.seg, b.seg, a.suf + b.pre}),
			max({a.pre, a.sum + b.pre}),
			max({b.suf, b.sum + a.suf}),
			a.sum + b.sum
		};
	}

	void build(int id, int l, int r, vector <int> &a) {
		if (l == r) {
			Tree[id] = makeNode(a[l]);
			return;
		}

		int mid = (l + r) / 2;
		build(2 * id, l, mid, a);
		build(2 * id + 1, mid + 1, r, a);

		Tree[id] = merge(Tree[2 * id], Tree[2 * id + 1]);
	}

	void update(int id, int l, int r, int i, ll val) {
		if (r < i || l > i) return;
		if (l == r) {
			Tree[id] = makeNode(val);
			return;
		}

		int mid = (l + r) / 2;
		update(2 * id, l, mid, i, val);
		update(2 * id + 1, mid + 1, r, i, val);

		Tree[id] = merge(Tree[2 * id], Tree[2 * id + 1]);
	}

	Node get(int id, int l, int r, int u, int v) {
		if (l > v || r < u) return Neutral;
		if (l >= u && r <= v) return Tree[id];

		int mid = (l + r) / 2;
		Node x = get(2 * id, l, mid, u, v);
		Node y = get(2 * id + 1, mid + 1, r, u, v);
		return merge(x, y);
	}

	void build(vector <int> &a) {
		build(1, 1, size, a);
	}

	void update(int i, int v) {
		update(1, 1, size, i, v);
	}

	ll get(int l, int r) {
		return get(1, 1, size, l, r).seg;
	}
};

int n, m;
vector <int> a(N);
SegmentTree st;

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	st.size = n;
	st.init(n);
	st.build(a);

	cout << st.get(1, n) << '\n';

	while (m--) {
		int u, v;
		cin >> u >> v;
		st.update(u + 1, v);
		cout << st.get(1, n) << '\n';
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
