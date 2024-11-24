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
	int N, K;
	cin >> N >> K;
	vector <int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	vector <int> ord(N);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int i, int j){
		return A[i] < A[j];
	});

	array <int, 3> ans;
	int max_val = 0;
	for (int i = 0; i + 1 < N; ++i) {
		int u = ord[i], v = ord[i + 1];
		int v1 = A[u], v2 = A[v];

		int x = 0;
		for (int j = 0; j < K; ++j) {
			int b1 = (v1 >> j) & 1;
			int b2 = (v2 >> j) & 1;

			if (b1 == b2) {
				x |= (b1 ^ 1) << j;
			}
		}

		if (((v1 ^ x) & (v2 ^ x)) >= max_val) {
			max_val = ((v1 ^ x) & (v2 ^ x));
			ans = {u + 1, v + 1, x};
		}
	}

	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
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