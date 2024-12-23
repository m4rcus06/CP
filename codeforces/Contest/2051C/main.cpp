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
	int n, m, k;
	cin >> n >> m >> k;
	vector <int> a(m);
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
		--a[i];
	}
	vector <int> q(k);
	int unknow = 0;
	for (int i = 0; i < k; ++i) {
		cin >> q[i];
		--q[i];
		if (i > 0) unknow += q[i] - q[i - 1] - 1;
	}
	unknow += n - q[k - 1] - 1 + q[0];

	vector <bool> marked(n);
	for (int i = 0; i < k; ++i) {
		marked[q[i]] = true;
	}

	for (int i = 0; i < m; ++i) {
		int cur = unknow;
		if (!marked[a[i]]) --cur;

		cout << (cur == 0 ? "1" : "0");
	}

	cout << '\n';
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