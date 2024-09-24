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