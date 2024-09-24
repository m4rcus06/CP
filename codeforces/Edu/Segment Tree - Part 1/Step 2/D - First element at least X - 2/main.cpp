/* https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/D */
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

struct SegmentTree {
	int size;
	vector <int> Tree;

	void init(int n) {
		Tree.resize(4 * n, 0);
	}

	int merge(int a, int b) {
		return max(a, b);
	}

	void build(int id, int l, int r, vector <int> &a) {
		if (l == r) {
			Tree[id] = a[l];
			return;
		}

		int mid = (l + r) / 2;
		build(2 * id, l, mid, a);
		build(2 * id + 1, mid + 1, r, a);

		Tree[id] = merge(Tree[2 * id], Tree[2 * id + 1]);
	}

	void update(int id, int l, int r, int i, int v) {
		if (l > i || r < i) return;
		if (l == r) {
			Tree[id] = v;
			return;
		}

		int mid = (l + r) / 2;
		update(2 * id, l, mid, i, v);
		update(2 * id + 1, mid + 1, r, i, v);

		Tree[id] = merge(Tree[2 * id], Tree[2 * id + 1]);
	}

	int getIDX(int id, int l, int r, int x, int pos) {
		if (r < pos || Tree[id] < x) return -1;
		if (l == r) return l - 1;

		int mid = (l + r) / 2;

		int idx = getIDX(2 * id, l, mid, x, pos);
		if (idx == -1) idx = getIDX(2 * id + 1, mid + 1, r, x, pos);
		return idx;
	}

	void build(vector <int> &a) {
		build(1, 1, size, a);
	}

	void update(int i, int v) {
		update(1, 1, size, i + 1, v);
	}

	int getIDX(int x, int pos) {
		return getIDX(1, 1, size, x, pos + 1);
	}
};

const int N = 1e5 + 1;

int n, m;
vector <int> a(N);
SegmentTree sTree;

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	sTree.size = n;
	sTree.init(n);
	sTree.build(a);

	while (m--) {
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1) sTree.update(x, y);
		else cout << sTree.getIDX(x, y) << '\n';
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
