/* https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/E */
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
	vector <ll> Tree;

	void init(int n) {
		Tree.resize(4 * n);
	}

	ll merge(ll a, ll b) {
		return a + b;
	}

	void build(int id, int l, int r, vector <ll> &a) {
		if (l == r) {
			Tree[id] = a[l];
			return;
		}

		int m = (l + r) / 2;
		build(2 * id, l, m, a);
		build(2 * id + 1, m + 1, r, a);

		Tree[id] = merge(Tree[2 * id], Tree[2 * id + 1]);
	}

	void update(int id, int l, int r, int u, ll v) {
		if (l > u || r < u) return;
		if (l == r) {
			Tree[id] += v;
			return;
		}

		int m = (l + r) / 2;
		update(2 * id, l, m, u, v);
		update(2 * id + 1, m + 1, r, u, v);

		Tree[id] = merge(Tree[2 * id], Tree[2 * id + 1]);
	}

	ll get(int id, int l, int r, int u, int v) {
		if (l > v || r < u) return 0LL;
		if (l >= u && r <= v) return Tree[id];

		int m = (l + r) / 2;
		ll x = get(2 * id, l, m, u, v);
		ll y = get(2 * id + 1, m + 1, r, u, v);

		return x + y;
	}

	void build(vector <ll> &a) {
		build(1, 1, size, a);
	}

	void update(int u, ll v) {
		update(1, 1, size, u + 1, v);
	}

	ll get(int u, int v) {
		return get(1, 1, size, u, v + 1);
	}
};

const int N = 1e5 + 1;

int n, m;
vector <ll> a(N);

void solve() {
	cin >> n >> m;

	SegmentTree St;
	St.size = n;
	St.init(n);

	while (m--) {
		int op;
		cin >> op;

		if (op == 1) {
			int l, r, v;
			cin >> l >> r >> v;
			St.update(l, 1LL * v);
			St.update(r, 1LL * (-v)); //indexing moment tho
		}
		else {
			int k;
			cin >> k;
			cout << St.get(1, k) << '\n';
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
