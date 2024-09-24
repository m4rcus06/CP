/* Just a short template */
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

const int inf = 1e9 + 7;

struct event {
	int p, m, t;
};

void solve() {
	int n, m, d, s;
	cin >> n >> m >> d >> s;
	vector <event> a(d + 1, {0, 0, 0});
	for (int i = 1; i <= d; ++i) {
		cin >> a[i].p >> a[i].m >> a[i].t;
	}

	vector <int> isSick(n + 1, -inf);
	for (int i = 1; i <= s; ++i) {
		int p, t;
		cin >> p >> t;
		isSick[p] = t;
	}

	//adding the type of milk which is drank by people who got sick
	set <int> st;
	for (int i = 1; i <= d; ++i) {
		if (a[i].t < isSick[a[i].p]) st.insert(a[i].m);
	}

	//removing the type of milk that have no possibility to be contaminated
	vector <int> notSus;
	for (auto it : st) {
		vector <bool> mark(n + 1, false);
		for (int i = 1; i <= d; ++i) {
			//the milk they drank before getting sick
			if (a[i].m == it && a[i].t < isSick[a[i].p]) mark[a[i].p] = true;
		}
		int cnt = 0;
		for (int i = 1; i <= n; ++i) cnt += mark[i];
		//there is someone who didn't drink this type of milk but still get sick
		if (cnt < s) notSus.push_back(it);
	}
	for (auto it : notSus) st.erase(it);

	//now we only have the type of milk that is actually contaminated
	//simply calculate the answer
	int res = 0;
	for (auto it : st) {
		vector <bool> mark(n + 1, false);
		for (int i = 1; i <= d; ++i) {
			if (a[i].m == it) mark[a[i].p] = true;
		}

		int cnt = 0;
		for (int i = 1; i <= n; ++i) cnt += mark[i];
		res = max(res, cnt);
	}
	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("badmilk.in", "r", stdin);
	freopen("badmilk.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
