#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif

int ask(int c, int d) {
	cout << "? " << c << ' ' << d << endl;
	int res; cin >> res;
	return res;
}
 
void solve() {
	int f = 0;
	if (ask(0, 0) != 1) f = 1;

	array <int, 2> ans = {0, 0};
	for (int bit = 29; bit >= 0; --bit) {
		int x = ask(ans[0] | (1 << bit), ans[1]);
		int y = ask(ans[0], ans[1] | (1 << bit));

		if (x == -1 && y == 1) {
			ans[0] |= 1 << bit;
			ans[1] |= 1 << bit;
		} else if (x == y) {
			ans[f] |= 1 << bit;
			f = (x != 1);
		}
	}
	cout << "! " << ans[0] << ' ' << ans[1] << endl;
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