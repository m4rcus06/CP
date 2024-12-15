#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
	int n; cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		char c; cin >> c;
		a[i] = c - '0';
	}

	int ans = 1;
	for (int k = 2; k <= n; ++k) {
		vector <int> b = a;
		vector <int> x(n, 0);
		for (int i = 0; i < n; ++i) {
			if ((b[i] ^ x[i]) == 0 && i + k <= n) {
				x[i] ^= 1;
				if (i + k < n) x[i + k] ^= 1;
			}
			if (i + 1 < n) x[i + 1] ^= x[i];
		}
		
		for (int i = 0; i < n; ++i) {
			b[i] ^= x[i];
		}

		if (accumulate(b.begin(), b.end(), 0) == n) ans = k;
	}

	cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif
 
    int tt = 1;
    cin >> tt;
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