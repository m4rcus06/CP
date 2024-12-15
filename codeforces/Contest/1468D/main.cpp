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
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector <int> s(m);
	for (int i = 0; i < m; ++i) {
		cin >> s[i];
	}
	sort(s.begin(), s.end());

	int time_left = (a < b ? b - 1 : n - b);
	auto isGood = [&](int x) {
		for (int i = x - 1, cur_time = 1; i >= 0; --i) {
			if (cur_time + s[i] > time_left) return false;
			++cur_time;
		}
		return true;
	};

	int l = 0, r = min(m + 1, abs(b - a));
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (isGood(mid)) l = mid;
		else r = mid;
	}	

	cout << l << '\n';
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