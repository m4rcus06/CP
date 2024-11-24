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

	vector <int> px(N + 1, 0);
	for (int i = 0; i < N; ++i) {
		px[i + 1] = px[i] ^ A[i];
	}

	lli ans = 0;
	for (int i = 0; i < 32; ++i) {
		lli cnt = 0;
		int a = 1, b = 0;
		for (int j = 1; j <= N; ++j) {
			if ((px[j] >> i) & 1) {
				cnt += a;
				b++;
			} else {
				cnt += b;
				a++;
			}
		}

		ans += cnt * (1LL << i);
	}

	for (int i = 0; i < N; ++i) {
		ans -= A[i];
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