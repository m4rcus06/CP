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
	int N, M, Q;
	cin >> N >> M >> Q;
	vector <int> w(N);
	int sum_w = 0;
	for (int i = 0; i < N; ++i) {
		cin >> w[i];
		sum_w += w[i];
	}

	vector <int> cnt(1 << N, 0);
	for (int i = 0; i < M; ++i) {
		string v; cin >> v;

		int cur_v = 0;
		for (int j = 0; j < N; ++j) {
			if (v[j] == '1') cur_v |= (1 << j);
		}

		cnt[cur_v] += 1;
	}

	vector <vector <int>> value(1 << N);
	vector <vector <int>> sum(1 << N);
	for (int mask = 0; mask < (1 << N); ++mask) {
		vector <int> tot(sum_w + 1, 0);
		for (int sub = 0; sub < (1 << N); ++sub) {
			if (cnt[sub] == 0) continue;

			int x = mask ^ sub;
			int y = 0;
			for (int i = 0; i < N; ++i) {
				y += w[i];
				if ((x >> i) & 1) y -= w[i];
			} 
			tot[y] += cnt[sub];
		}

		for (int i = 0; i <= sum_w; ++i) {
			if (tot[i] != 0) {
				value[mask].push_back(i);
				if (!sum[mask].empty()) sum[mask].push_back(sum[mask].back() + tot[i]);
				else sum[mask].push_back(tot[i]);
			}
		}
	}

	while (Q--) {
		string t;
		int k;
		cin >> t >> k;

		int mask = 0;
		for (int i = 0; i < N; ++i) {
			if (t[i] == '1') mask |= (1 << i);
		}

		int idx = upper_bound(value[mask].begin(), value[mask].end(), k) - value[mask].begin() - 1;
		cout << (idx >= 0 ? sum[mask][idx] : 0) << '\n';
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