/* https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/E */
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
		Tree.resize(4 * n, INT_MAX);
	}


	int merge(int a, int b) {
		return min(a, b);
	}

	void build(int id, int l, int r, vector <int> &a) {
		if (l == r) {
			Tree[id] = a[l];
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
			Tree[id] = k;
			return;
		}

		int m = (l + r) / 2;
		update(2 * id, l, m, i, k);
		update(2 * id + 1, m + 1, r, i, k);

		Tree[id] = merge(Tree[2 * id], Tree[2 * id + 1]);
	}

	int i = 0;
	int get(int id, int l, int r, int u, int v, int p) {
		if (l > v || r < u || Tree[id] > p) return 0;
		if (l == r) {
			Tree[id] = INT_MAX;
			return 1;
		}
		int m = (l + r) / 2;
		int x = get(2 * id, l, m, u, v, p);
		int y = get(2 * id + 1, m + 1, r, u, v, p);

		Tree[id] = merge(Tree[2 * id], Tree[2 * id + 1]);
		return (x + y);
	}

	void build(vector <int> &a) {
		build(1, 1, size, a);
	}

	void update(int i, int k) {
		update(1, 1, size, i + 1, k);
	}

	int get(int u, int v, int p) {
		return get(1, 1, size, u + 1, v, p);
	}
};

const int N = 1e5 + 1;

int n, q;

void solve() {
	cin >> n >> q;

	SegmentTree St;
	St.size = n;
	St.init(n);

	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int i, h;
			cin >> i >> h;
			St.update(i, h);
		}
		else {
			int l, r, p;
			cin >> l >> r >> p;
			cout << St.get(l, r, p) << '\n';
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
