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
	int N; cin >> N;
	vector <int> p(N);
	for (int i = 0; i < N; ++i) {
		cin >> p[i];
	}
	int x, y, a, b;
	lli k;
	cin >> x >> a >> y >> b >> k;
	sort(p.begin(), p.end(), greater <int>());

	vector <int> profit(N);
	for (int i = a; i <= N; i += a) {
		profit[i - 1] += x;
	}
	for (int i = b; i <= N; i += b) {
		profit[i - 1] += y;
	}

	auto cost = [&](int x) -> lli {
		lli res = 0;
		int cnt = 0;
		vector <int> coeff;
		for (int i = 0; i < x; ++i) {
			if (profit[i] != 0) {
				++cnt;
				coeff.push_back(profit[i]);
			}
		}
		sort(coeff.begin(), coeff.end(), greater <int>());

		for (int i = 0; i < cnt; ++i) {
			res += 1LL * coeff[i] * (p[i] / 100);
		}

		return res;
	};

	int l = 0, r = N + 1;
	while (r - l > 1) {
		int m = (l + r) / 2;

		if (cost(m) >= k) r = m;
		else l = m;
	}

	cout << (r == N + 1 ? -1 : r) << '\n';
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