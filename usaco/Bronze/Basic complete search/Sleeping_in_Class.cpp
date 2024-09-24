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
	int n;
	cin >> n;
	vector <int> a(n + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	int sum = 0;
	for (int i = 1; i <= n; ++i) sum += a[i];

	vector <int> pre(n + 1, 0);
	for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];

	int res = n;
	for (int x = 1; x * x <= sum; ++x) {
		if (sum % x == 0) {
			int cur = x, cnt = 0;
			bool flag = true;
			for (int i = 1, last = 1; i <= n; ) {
				last = i;
				i = lower_bound(all(pre), cur) - pre.begin();
				if (pre[i] == cur) {
					cur += x;
					cnt += i - last;
				}
				else {
					flag = false;
					break;
				}
				++i;
			}
			if (flag) res = min(res, cnt);

			if (x != sum / x) {
				int cur = sum / x, cnt = 0;
				bool flag = true;
				for (int i = 1, last = 1; i <= n;) {
					last = i;
					i = lower_bound(all(pre), cur) - pre.begin();
					if (pre[i] == cur) {
						cur += sum / x;
						cnt += i - last;
					}
					else {
						flag = false;
						break;
					}
					++i;
				}
				if (flag) res = min(res, cnt);
			}
		}
	}

	if (sum == 0) res = 0;
	cout << res << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
