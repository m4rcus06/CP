/* https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/C */
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
	int x;
};

struct SegmentTree {
	int n;
	vector <Node> Tree;
	Node Neutral = {INT_MIN};

	void init(int n) {
		Tree.resize(4 * n, Neutral);
	}

	Node makeNode(int x) {
		return {x};
	}

	Node merge(Node a, Node b) {
		return {max(a.x, b.x)};
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

	void update(int id, int l, int r, int i, int v) {
		if (l > i || r < i) return;
		if (l == r) {
			Tree[id] = makeNode(v);
			return;
		}

		int mid = (l + r) / 2;
		update(2 * id, l, mid, i, v);
		update(2 * id + 1, mid + 1, r, i, v);

		Tree[id] = merge(Tree[2 * id], Tree[2 * id + 1]);
	}

	int getIDX(int id, int l, int r, int x) {
		if (l == r) {
			if (Tree[id].x < x) return -1;
			return l - 1; //idx start from 0 so substract 1
		}

		int mid = (l + r) / 2;
		if (Tree[2 * id].x >= x) return getIDX(2 * id, l, mid, x);
		return getIDX(2 * id + 1, mid + 1, r, x);
	}

	void build(vector <int> &a) {
		build(1, 1, n, a);
	}

	void update(int i, int v) {
		update(1, 1, n, i + 1, v); //idx start from 0
	}

	int getIDX(int x) {
		return getIDX(1, 1, n, x);
	}
};

const int N = 1e5 + 1;

int n, m;
vector <int> a(N);
SegmentTree st;

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	st.n = n;
	st.init(n);
	st.build(a);

	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int i, v;
			cin >> i >> v;
			st.update(i, v);
		}
		else {
			int x;
			cin >> x;
			cout << st.getIDX(x) << '\n';
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
