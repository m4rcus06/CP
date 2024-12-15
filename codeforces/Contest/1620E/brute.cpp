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
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int q; cin >> q;
	vector <int> ans;
	for (int i = 0; i < q; ++i) {
		int t; cin >> t;
		if (t == 1) {
			int x; cin >> x;
			ans.push_back(x);
		} else {
			int x, y;
			cin >> x >> y;
			for (int j = 0; j < (int) ans.size(); ++j) {
				if (ans[j] == x) ans[j] = y;
			}
		}
	}

	for (int &x : ans) cout << x << ' ';
	cout << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
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