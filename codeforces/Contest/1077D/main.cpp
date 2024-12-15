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

	int mx = *max_element(A.begin(), A.end());
	vector <int> cnt(mx + 1, 0);
	for (int i = 0; i < N; ++i) {
		cnt[A[i]] += 1;
	}

	auto isGood = [&](int x) -> bool {
		int len = 0;
		for (int i = 1; i <= mx; ++i) {
			len += cnt[i] / x;
		}

		return len >= K;
	};

	int l = 1, r = N / K + 1;
	while (r - l > 1) {
		int m = (l + r) / 2;

		if (isGood(m)) l = m;
		else r = m;
	}

	vector <int> ans;
	for (int i = 1; i <= mx; ++i) {
		int can = cnt[i] / l;
		while ((int) ans.size() < K && can > 0) {
			ans.emplace_back(i);
			can--;
		}
	}

	for (int i = 0; i < (int) ans.size(); ++i) {
		cout << ans[i] << ' ';
	}
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