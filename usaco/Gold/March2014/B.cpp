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
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	auto isGood = [&](double x) -> bool {
		vector <double> S(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			S[i + 1] = S[i] + 1.0 * a[i] - x;
		}

		double mn = S[1];
		for (int i = 2; i < n; ++i) {
			if (S[n] - S[i] + mn <= 0) return true;
			mn = min(mn, S[i]);
		}

		return false;
	};

	double l = 0, r = 1e9;
	for (int iter = 0; iter < 64; ++iter) {
		double m = (l + r) / 2;
		if (isGood(m)) r = m;
		else l = m;
	}

	cout << setprecision(3) << fixed;
	cout << r << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("sabotage.in", "r", stdin);
    freopen("sabotage.out", "w", stdout);
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