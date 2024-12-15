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
	vector <int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	vector <int> cnt(20, 0);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 20; ++j) {
			if ((A[i] >> j) & 1) cnt[j] += 1;
		}
	}

	lli ans = 0;
	for (int i = 0; i < N; ++i) {
		int v = 0;
		for (int j = 0; j < 20; ++j) {
			if (cnt[j] > 0) {
				v |= 1 << j;
				--cnt[j];
			}
		}

		ans += 1LL * v * v;
	}

	cout << ans << '\n';
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