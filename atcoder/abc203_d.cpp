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
	int N, K; cin >> N >> K;
	vector <vector <int>> A(N, vector <int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}


	vector <vector <int>> P(N + 1, vector <int>(N + 1, 0));
	auto sum = [&](int x, int y, int u, int v) -> int {
		return P[u][v] - P[x - 1][v] - P[u][y - 1] + P[x - 1][y - 1];
	};

	auto isGood = [&](int x) -> bool {
		fill(P.begin(), P.end(), vector <int> (N + 1, 0));
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + (A[i - 1][j - 1] <= x ? 1 : - 1);
			}
		}

		for (int i = 1; i <= N - K + 1; ++i) {
			for (int j = 1; j <= N - K + 1; ++j) {
				if(sum(i, j, i + K - 1, j + K - 1) >= 0) return true;
			}
		}

		return false;
	};

	int l = -1, r = (int) 1e9;
	while (r - l > 1) {
		int m = (l + r) / 2;

		if (isGood(m)) r = m;
		else l = m;
	}

	cout << r << '\n';
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