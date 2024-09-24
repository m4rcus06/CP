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

int n, m;
vector <string> spt, pln;
int arr[] = {0, 1, 2, 3}; //A-C-G-T

int calc(char ch) {
	if (ch == 'A') return 0;
	if (ch == 'C') return 1;
	if (ch == 'G') return 2;
	return 3;
}

bool good(int i, int j, int k) {
	vector <bool> cnt(64, 0);
	for (int x = 1; x <= n; ++x) {
		string cur = {spt[x][i], spt[x][j], spt[x][k]};
		int val = calc(cur[0]) * 16 + calc(cur[1]) * 4 + calc(cur[2]);
		cnt[val] = 1;
	}
	for (int x = 1; x <= n; ++x) {
		string cur = {pln[x][i], pln[x][j], pln[x][k]};
		int val = calc(cur[0]) * 16 + calc(cur[1]) * 4 + calc(cur[2]);
		if (cnt[val]) return 0;
	}
	return 1;
}

void solve() {
	cin >> n >> m;
	spt.resize(n + 1);
	pln.resize(n + 1);
	for (int i = 1; i <= n; ++i) cin >> spt[i];
	for (int i = 1; i <= n; ++i) cin >> pln[i];

	int res = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			for (int k = j + 1; k < m; ++k) {
				res += good(i, j, k);
			}
		}
	}

	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
