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

void solve() {
	string s; cin >> s;
	vector <int> cnt(26, -1);

	int res = 0;
	for (int i = 0; i < sz(s); ++i) {
		if (cnt[s[i] - 'A'] == -1) cnt[s[i] - 'A'] = i;
		else {
			int l = cnt[s[i] - 'A'], r = i;
			cnt[s[i] - 'A'] = -1;
			for (int i = 0; i < 26; ++i) {
				res += (cnt[i] >= l && cnt[i] <= r);;
			}
		}
	}

	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
