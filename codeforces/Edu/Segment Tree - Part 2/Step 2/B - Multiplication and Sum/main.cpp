/* https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/B */
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

//Thank you GlowCheese
template <const int m>
struct Mint {
	typedef long long lli;
	int v; static_assert(m > 0);
	Mint(lli value = 0): v(value % m) { if (value < 0) value += m; }
	friend istream& operator >> (istream& inp, Mint& a) {
		lli x; inp >> x;
		a = x; return inp;
	}
	friend ostream& operator << (ostream& out, const Mint& a) { out << a.v; return out; }

	Mint operator + () { return *this; }
	Mint operator - () { return Mint() - *this; }

	Mint& operator++() { if (++v, v == m) v = 0; return *this; }
	Mint& operator--() { if (v == 0) v = m; --v; return *this; }
	Mint operator++(int) { Mint ans = *this; ++*this; return ans; }
	Mint operator--(int) { Mint ans = *this; --*this; return ans; }

	Mint& operator += (const Mint& other) { if (v += other.v, v >= m) v -= m; return *this; }
	Mint& operator -= (const Mint& other) { if (v -= other.v, v < 0) v += m; return *this; }
	Mint& operator *= (const Mint& other) { v = int64_t(v) * other.v % m; return *this; }
	Mint inv() const {
		int a = 1, b = 0;
		for (int x = v, y = m; x != 0;)
			swap(a, b -= y / x * a), swap(x, y -= y / x * x);
		if (b < 0) b += m;
		return b;
	}
	Mint& operator /= (const Mint& other) { return *this *= other.inv(); }

	friend Mint operator + (const Mint& a, const Mint& b) { return Mint(a) += b; }
	friend Mint operator - (const Mint& a, const Mint& b) { return Mint(a) -= b; }
	friend Mint operator * (const Mint& a, const Mint& b) { return Mint(a) *= b; }
	friend Mint operator / (const Mint& a, const Mint& b) { return Mint(a) /= b; }

	friend bool operator == (const Mint& a, const Mint& b) { return a.v == b.v; }
	friend bool operator != (const Mint& a, const Mint& b) { return a.v != b.v; }
};

const int mod = 1e9 + 7;
using mint = Mint <mod>;

struct Node {
	mint val = 0;
	mint lazy = 1;
};

struct SegmentTree {
	int size;
	vector <Node> Tree;
	mint Neutral = 0;

	void init(int n) {
		Tree.resize(4 * n);
	}

	void build(int id, int lx, int rx) {
		if (lx == rx) {
			Tree[id] = {1, 1};
			return;
		}

		int mx = (lx + rx) >> 1;
		build(2 * id, lx, mx);
		build(2 * id + 1, mx + 1, rx);
		Tree[id].val = Tree[2 * id].val + Tree[2 * id + 1].val;
	}

	void build() {
		build(1, 1, size);
	}

	void update(int id, int lx, int rx, int u, int v, mint k) {
		if (lx > v || rx < u) return;
		if (lx >= u && rx <= v) {
			Tree[id].val *= k;
			Tree[id].lazy *= k;
			return;
		}

		int mx = (lx + rx) >> 1;
		update(2 * id, lx, mx, u, v, k);
		update(2 * id + 1, mx + 1, rx, u, v, k);
		Tree[id].val = (Tree[2 * id].val + Tree[2 * id + 1].val) * Tree[id].lazy;
	}

	void update(int l, int r, mint v) {
		update(1, 1, size, l + 1, r, v);
	}

	mint query(int id, int lx, int rx, int u, int v) {
		if (lx > v || rx < u) return Neutral;
		if (lx >= u && rx <= v) return Tree[id].val;

		int mx = (lx + rx) >> 1;
		mint x1 = query(2 * id, lx, mx, u, v);
		mint x2 = query(2 * id + 1, mx + 1, rx, u, v);
		return (x1 + x2) * Tree[id].lazy;
	}

	mint query(int l, int r) {
		return query(1, 1, size, l + 1, r);
	}
};

void solve() {
	int n, q;
	cin >> n >> q;

	SegmentTree St;
	St.size = n;
	St.init(n);
	St.build();

	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			int l, r;
			mint v;
			cin >> l >> r >> v;
			St.update(l, r, v);
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
