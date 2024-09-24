/* https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/B */
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
	int x;
};

struct SegmentTree {
	int size;
	vector <Node> Tree;
	Node Neutral = {0};

	void init(int N) {
		Tree.resize(4 * N, Neutral);
	}

	Node makeNode(int a) {
		return {a};
	}

	Node merge(Node a, Node b) {
		return makeNode(a.x + b.x);
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

	void update(int id, int l, int r, int i) {
		if (r < i || l > i) return;
		if (l == r) {
			Tree[id].x ^= 1;
			return;
		}

		int mid = (l + r) / 2;
		update(2 * id, l, mid, i);
		update(2 * id + 1, mid + 1, r, i);

		Tree[id] = merge(Tree[2 * id], Tree[2 * id + 1]);
	}

	int getIDX(int id, int l, int r, int k) {
		if (l == r) return l;

		int mid = (l + r) / 2;
		if (k <= Tree[2 * id].x)
			return getIDX(2 * id, l, mid, k);
		return getIDX(2 * id + 1, mid + 1, r, k - Tree[2 * id].x);
	}

	void build(vector <int>&a) {
		build(1, 1, size, a);
	}

	void update(int idx) {
		update(1, 1, size, idx);
	}

	int getIDX(int k) {
		return getIDX(1, 1, size, k);
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

	while (m--) {
		int type, x;
		cin >> type >> x;
		if (type == 1) st.update(x + 1); //the problem's idx start from 0;
		else cout << st.getIDX(x + 1) - 1 << '\n';
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
