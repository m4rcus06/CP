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
	int n, a, b, c;
	cin >> n >> a >> b >> c;

	lli ans = (n / (a + b + c)) * 3;
	n %= (a + b + c);

	if (n > a + b) ans += 3;
	else if (n > a) ans += 2;
	else if (n > 0) ans += 1;

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