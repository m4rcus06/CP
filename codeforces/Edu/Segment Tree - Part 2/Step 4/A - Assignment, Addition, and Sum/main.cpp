/* https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/A */
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
	ll sum, add, set;
};

struct segTree {
	int size;
	vector <Node> Tree;
	const int NA = -1;

	void init(int n) {
		Tree.resize(4 * n, {0, 0, NA});
	}

	void push(int id, int lx, int rx) {
		int mx = (lx + rx) >> 1;

		if (Tree[id].set != NA) {
			Tree[2 * id].sum = 1LL * (mx - lx + 1) * Tree[id].set;
			Tree[2 * id + 1].sum = 1LL * (rx - mx) * Tree[id].set;
			Tree[2 * id].set = Tree[2 * id + 1].set = Tree[id].set;

			Tree[2 * id].add = Tree[2 * id + 1].add = 0; //the set operation will override the add operation
			Tree[id].set = NA;
		}
		else if (Tree[id].add != 0) {
			if (Tree[2 * id].set == NA) Tree[2 * id].add += Tree[id].add;
			else {
				Tree[2 * id].set += Tree[id].add; //explain : we have been set [l, r] to x and add y, which mean we set [l, r] to x + y
				Tree[2 * id].add = 0; //override
			}
			if (Tree[2 * id + 1].set == NA) Tree[2 * id + 1].add += Tree[id].add;
			else {
				Tree[2 * id + 1].set += Tree[id].add;
				Tree[2 * id + 1].add = 0;
			}
			Tree[2 * id].sum += 1LL * (mx - lx + 1) * Tree[id].add;
			Tree[2 * id + 1].sum += 1LL * (rx - mx) * Tree[id].add;
			Tree[id].add = 0;
		}
	}

	void add(int id, int lx, int rx, int u, int v, ll k) {
		if (lx > v || rx < u) return;
		if (lx >= u && rx <= v) {
			Tree[id].sum += 1LL * (rx - lx + 1) * k;
			if (Tree[id].set == NA) Tree[id].add += k;
			else Tree[id].set += k;
			return;
		}
		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		add(2 * id, lx, mx, u, v, k);
		add(2 * id + 1, mx + 1, rx, u, v, k);

		Tree[id].sum = Tree[2 * id].sum + Tree[2 * id + 1].sum;
	}

	void add(int l, int r, ll k) {
		add(1, 1, size, l + 1, r, k);
	}

	void set(int id, int lx, int rx, int u, int v, ll k) {
		if (lx > v || rx < u) return;
		if (lx >= u && rx <= v) {
			Tree[id].sum = 1LL * (rx - lx + 1) * k;
			Tree[id].set = k;
			Tree[id].add = 0; //override
			return;
		}

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		set(2 * id, lx, mx, u, v, k);
		set(2 * id + 1, mx + 1, rx, u, v, k);

		Tree[id].sum = Tree[2 * id].sum + Tree[2 * id + 1].sum;
	}

	void set(int l, int r, ll k) {
		set(1, 1, size, l + 1, r, k);
	}

	ll query(int id, int lx, int rx, int u, int v) {
		if (lx > v || rx < u) return 0;
		if (lx >= u && rx <= v) return Tree[id].sum;

		push(id, lx, rx);
		int mx = (lx + rx) >> 1;
		ll x1 = query(2 * id, lx, mx, u, v);
		ll x2 = query(2 * id + 1, mx + 1, rx, u, v);

		return (x1 + x2);
	}

	ll query(int l, int r) {
		return query(1, 1, size, l + 1, r);
	}
};

void solve() {
	int n, q;
	cin >> n >> q;

	segTree St;
	St.size = n;
	St.init(n);

	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			ll l, r, v;
			cin >> l >> r >> v;
			St.set(l, r, 1LL * v);
		}
		else if (type == 2) {
			ll l, r, v;
			cin >> l >> r >> v;
			St.add(l, r, 1LL * v);
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
