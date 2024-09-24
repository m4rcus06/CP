/* https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/B */
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
	ll xx, xy, yx, yy;
};

struct SegmentTree {
	int size;
	vector <Node> Tree;
	Node Neutral = {1, 0, 0, 1}; //doesnt change the value if multiply A with Neutral

	void init(int n) {
		Tree.resize(4 * n, {0, 0, 0, 0});
	}

	Node merge(Node a, Node b, ll MOD) { //2x2 matrix
		return {
			((a.xx * b.xx) % MOD + (a.xy * b.yx) % MOD) % MOD,
			((a.xx * b.xy) % MOD + (a.xy * b.yy) % MOD) % MOD,
			((a.yx * b.xx) % MOD + (a.yy * b.yx) % MOD) % MOD,
			((a.yx * b.xy) % MOD + (a.yy * b.yy) % MOD) % MOD,
		};
	}

	void build(int id, int l, int r, vector<Node> &a, ll MOD) {
		if (l == r) {
			Tree[id] = a[l];
			return;
		}

		int m = (l + r) / 2;
		build(2 * id, l, m, a, MOD);
		build(2 * id + 1, m + 1, r, a, MOD);

		Tree[id] = merge(Tree[2 * id], Tree[2 * id + 1], MOD);
	}

	Node get(int id, int l, int r, int u, int v, ll MOD) {
		if (l > v || r < u) return Neutral;
		if (l >= u && r <= v) return Tree[id];

		int m = (l + r) / 2;
		Node x = get(2 * id, l, m, u, v, MOD);
		Node y = get(2 * id + 1, m + 1, r, u, v, MOD);

		return merge(x, y, MOD);
	}

	void build(vector <Node> &a, ll MOD) {
		build(1, 1, size, a, MOD);
	}

	Node get(int u, int v, ll MOD) {
		return get(1, 1, size, u, v, MOD);
	}
};

const int N = 2e5 + 1;

int n, m;
ll MOD;
vector <Node> a(N);

void solve() {
	cin >> MOD >> n >> m;;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].xx >> a[i].xy >> a[i].yx >> a[i].yy;
	}

	SegmentTree St;
	St.size = n;
	St.init(n);
	St.build(a, MOD);

	while (m--) {
		int l, r;
		cin >> l >> r;
		Node ans = St.get(l, r, MOD);

		cout << ans.xx << ' ' << ans.xy << '\n' << ans.yx << ' ' << ans.yy << '\n';
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
