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
		--p[i];
	}

	vector <bool> vis(N, false);
	for (int i = 0; i < N; ++i) {
		fill(vis.begin(), vis.end(), false);

		int pos = i;
		while (!vis[pos]) {
			vis[pos] = true;
			pos = p[pos];
		}
		cout << pos + 1 << ' ';
	}
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