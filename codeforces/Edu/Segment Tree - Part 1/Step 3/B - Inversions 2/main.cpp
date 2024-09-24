/* https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/B */
/**/
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
		return a + b;
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

	void update(int id, int l, int r, int i, int val) {
		if (l > i || r < i) return;
		if (l == r) {
			Tree[id] = val;
			return;
		}

		int mid = (l + r) / 2;
		update(2 * id, l, mid, i, val);
		update(2 * id + 1, mid + 1, r, i, val);

		Tree[id] = merge(Tree[2 * id], Tree[2 * id + 1]);
	}

	int get(int id, int l, int r, int k) {
		if (l == r) return l;

		int mid = (l + r) / 2;
		if (k > Tree[2 * id + 1]) return get(2 * id, l, mid, k - Tree[2 * id + 1]);
		return get(2 * id + 1, mid + 1, r, k);

	}

	void build(vector <int> &a) {
		build(1, 1, size, a);
	}

	void update(int i, int k) {
		update(1, 1, size, i, k);
	}

	int get(int x) {
		return get(1, 1, size, x + 1);
	}

};

const int N = 1e5 + 1;

int n;
vector <int> vis(N, 1), a(N);
SegmentTree sTree;

void solve() {
	cin >> n;

	sTree.size = n;
	sTree.init(n);
	sTree.build(vis);

	for (int i = 1; i <= n; ++i) cin >> a[i];

	vector <int> res;
	for (int i = n; i > 0; --i) {
		int x = sTree.get(a[i]);
		res.push_back(x);
		sTree.update(x, 0);
	}

	reverse(all(res));
	for (auto it : res) cout << it <<  ' ';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
