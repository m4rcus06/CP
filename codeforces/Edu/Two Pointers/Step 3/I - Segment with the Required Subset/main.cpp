/* https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/I */
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
const int LIM = 1001;

int n, s, a[N];
stack <int> s1, s2;
vector <bitset<LIM>> L = {0}, R = {0};

void add(int x) {
	s2.push(x);
	R.push_back(R.back() | (R.back() >> x));
}

void rev() {
	if (s1.empty()) {
		while (!s2.empty()) {
			s1.push(s2.top());
			L.push_back(L.back() | (L.back() << s2.top()));
			s2.pop();
			R.pop_back();
		}
	}
	s1.pop();
	L.pop_back();
}

bool good() {
	return (L.back() & R.back()).any();
}

void solve() {
	cin >> n >> s;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	//Indexed start from the right
	L[0][0] = R[0][s] = 1;

	int res = n + 1;
	for (int l = 1, r = 1; r <= n; ++r) {
		add(a[r]);
		while (good()) {
			res = min(res, r - l + 1);
			rev();
			l++;
		}
	}
	cout << (res <= n ? res : -1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
