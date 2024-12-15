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
	int C, N; cin >> C >> N;
	vector <int> A(N);
	for (int i = 0; i < N; ++i) {
		string S; cin >> S;
		for (int j = 0; j < C; ++j) {
			if (S[j] == 'G') A[i] |= 1 << j;
		}	
	}

	vector <int> dp(1 << C, C + 1);
	for (int i = 0; i < N; ++i) {
		dp[A[i]] = 0;
	}

	for (int i = 0; i < C; ++i) {
		for (int mask = 0; mask < (1 << C); ++mask) {
			if (dp[mask] != C + 1) {
				dp[mask ^ (1 << i)] = min(dp[mask ^ (1 << i)], dp[mask] + 1);
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		int inv_mask = ((1 << C) - 1) ^ A[i];
		cout << C - dp[inv_mask] << '\n';
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