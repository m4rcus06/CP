#include <bits/stdc++.h>
using namespace std;

//replace with your directory
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif


//only for integers type
using lli = int64_t;
 
template <const int m> 
struct Mint {
	int v; static_assert(m > 0);
	Mint(lli value = 0): v(value % m) { if (v < 0) v += m; }
	friend istream& operator >> (istream& inp, Mint& a) {
		lli x; inp >> x;
		a = x; return inp;
	}
	friend ostream& operator << (ostream& out, const Mint& a) { out << a.v; return out; }
	
	Mint operator + () const { return *this; }
	Mint operator - () const { return Mint() - *this; }
	
	Mint& operator++() { ++v; if (v == m) v = 0; return *this; }
	Mint& operator--() { if (v == 0) v = m; --v; return *this; }
	Mint operator++(int) { Mint ans = *this; ++*this; return ans; }
	Mint operator--(int) { Mint ans = *this; --*this; return ans; }
	
	Mint& operator += (const Mint& other) { v += other.v; if (v >= m) v -= m; return *this; }
	Mint& operator -= (const Mint& other) { v -= other.v; if (v < 0) v += m; return *this; }
	Mint& operator *= (const Mint& other) { v = int64_t(v) * other.v % m; if (v < 0) v += m; return *this; }
	Mint inv() const {
		lli a = 1, b = 0;
		for (lli x = v, y = m; x != 0;)
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
 
const int mod = (int) 1e9 + 7;
using mint = Mint <mod>;

struct matrix {
    mint a[2][2];

    matrix() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                a[i][j] = mint(0);
            }
        }
    }
};

matrix operator * (const matrix &a, const matrix &b) {
    matrix c;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                c.a[i][j] += a.a[i][k] * b.a[k][j];
            }
        }
    }
    return c;
}

matrix pow (matrix a, int n) {
    matrix res;
    res.a[0][0] = res.a[1][1] = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }

    return res;
}

const int N = 1e5 + 5;

matrix tree[4 * N], lazy[4 * N];
matrix unit = matrix();

void push (int x, int tl, int tr) {
    bool valid = false;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (lazy[x].a[i][j] != 0) valid = true; 
        }
    }
    if (!valid) return;

    int m = (tl + tr) / 2;
    lazy[2 * x] = lazy[2 * x + 1] = lazy[x];
    tree[2 * x] = pow (lazy[x], m - tl + 1);
    tree[2 * x + 1] = pow (lazy[x], tr - m);

    lazy[x] = matrix();
}

void modify (int x, int tl, int tr, int l, int r, const matrix &v) {
    if (tl > r || tr < l) return;
    if (tl >= l && tr <= r) {
        tree[x] = pow (v, tr - tl + 1);
        lazy[x] = v;
        return;
    }

    push (x, tl, tr);
    int m = (tl + tr) / 2;
    modify (2 * x, tl, m, l, r, v);
    modify (2 * x + 1, m + 1, tr, l, r, v);

    tree[x] = tree[2 * x] * tree[2 * x + 1];
}

matrix query (int x, int tl, int tr, int l, int r) {
    if (tl > r || tr < l) return unit;
    if (tl >= l && tr <= r) return tree[x];

    push (x, tl, tr);
    int m = (tl + tr) / 2;
    return query (2 * x, tl, m, l, r) * query(2 * x + 1, m + 1, tr, l, r);
}

matrix op[2];
void init() {
    op[0].a[0][0] = mint(1);
    op[0].a[0][1] = mint(-1);
    op[0].a[1][0] = mint(1);
    op[0].a[1][1] = mint(1);

    op[1].a[0][0] = mint(1);
    op[1].a[0][1] = mint(1);
    op[1].a[1][0] = mint(-1);
    op[1].a[1][1] = mint(1);

    unit.a[0][0] = mint(1);
    unit.a[1][1] = mint(1);
}
 
void solve() {
    int N, Q; cin >> N >> Q;
    init();
    for (int i = 1; i <= N; ++i) {
        char c; cin >> c;
        modify (1, 1, N, i, i, op[c - 'A']);
    }


    while (Q--) {
        int type; cin >> type;

        if (type == 1) {
            int L, R; cin >> L >> R;
            char c; cin >> c;

            modify (1, 1, N, L, R, op[c - 'A']);
        } else {
            int L, R, x, y;
            cin >> L >> R >> x >> y;
            
            matrix cur;
            cur.a[0][0] = mint(x);
            cur.a[1][0] = mint(y);

            matrix ans = query (1, 1, N, L, R);
            ans = ans * cur;

            cout << ans.a[0][0] << ' ' << ans.a[1][0] << '\n';
        }
    }
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif
 
    int tt = 1;
    while (tt--) {
        solve();
    }
 
#ifdef LOCAL
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
#endif
 
    return 0;
}
