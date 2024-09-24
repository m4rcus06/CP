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

const int N = 1e6 + 1;

bool isPrime[N];
vector <int> primes;

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			if (i > m) cout << "YES" << '\n';
			else cout << "NO" << '\n';
			return;
		}
	}

	if (n > m || n == 1) cout << "YES" << '\n';
	else cout << "NO" << '\n';
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
