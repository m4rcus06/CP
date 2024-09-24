/* https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/D */
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
	ll sum = 0;
	ll weight = 0;
	ll lazy = 0;
};

struct segTree {
	int size;
	vector <Node> Tree;

	void init(int n) {
		Tree.resize(4 * n, {0, 0, 0});
	}

	ll calc(ll l, ll r) {
		return 1LL * (r - l + 1) * (l + r) / 2;
	}

	void build(int id, int lx, int rx, vector <ll> &a) {
		if (lx == rx) {
			Tree[id] = {a[lx], 1LL * a[lx] * lx, 0};
			return;
		}

		int mx = (lx + rx) >> 1;
		build(2 * id, lx, mx, a);
		build(2 * id + 1, mx + 1, rx, a);

		Tree[id].sum = Tree[2 * id].sum + Tree[2 * id + 1].sum;
		Tree[id].weight = Tree[2 * id].weight + Tree[2 * id + 1].weight;
	}

	void build(vector <ll> &a) {
		build(1, 1, size, a);
	}

	void push(int id, int lx, int rx) {
		int mx = (lx + rx) >> 1;

		Tree[2 * id].sum += 1LL * (mx - lx + 1) * Tree[id].lazy;
		Tree[2 * id].weight += 1LL * calc(lx, mx) * Tree[id].lazy;
		Tree[2 * id].lazy += Tree[id].lazy;

		Tree[2 * id + 1].sum += 1LL * (rx - mx) * Tree[id].lazy;
		Tree[2 * id + 1].weight += 1LL * calc(mx + 1, rx) * Tree[id].lazy;
		Tree[2 * id + 1].lazy += Tree[id].lazy;

		Tree[id].lazy = 0;
	}

	void update(int id, int lx, int rx, int u, int v, ll d) {
		if (lx > v || rx < u) return;
		if (lx >= u && rx <= v) {
			Tree[id].sum += 1LL * (rx - lx + 1) * d;
			Tree[id].weight += 1LL * calc(lx, rx) * d;
			Tree[id].lazy += d;
			return;
		}

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		update(2 * id, lx, mx, u, v, d);
		update(2 * id + 1, mx + 1, rx, u, v, d);

		Tree[id].sum = Tree[2 * id].sum + Tree[2 * id + 1].sum;
		Tree[id].weight = Tree[2 * id].weight + Tree[2 * id + 1].weight;
	}

	void update(int u, int v, ll d) {
		update(1, 1, size, u, v, d);
	}

	pll query(int id, int lx, int rx, int u, int v) {
		if (lx > v || rx < u) return {0, 0};
		if (lx >= u && rx <= v) return {Tree[id].sum, Tree[id].weight};

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		pll x1 = query(2 * id, lx, mx, u, v);
		pll x2 = query(2 * id + 1, mx + 1, rx, u, v);

		return {x1.st + x2.st, x1.nd + x2.nd};
	}

	ll query(int u, int v) {
		pll ans = query(1, 1, size, u, v);
		return 1LL * ans.nd - ans.st * (u - 1);
	}
};

void solve() {
	int n, q;
	cin >> n >> q;
	vector <ll> a(n + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	segTree St;
	St.size = n;
	St.init(n);
	St.build(a);

	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			int l, r;
			ll d;
			cin >> l >> r >> d;
			St.update(l, r, 1LL * d);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << St.query(l, r) << '\n';
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
