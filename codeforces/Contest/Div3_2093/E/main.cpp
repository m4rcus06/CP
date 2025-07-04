#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/mycp/Library/debug.h>
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

	auto possible = [&](int x) {
		vector <int> freq(N + 1, 0);
		int cur_mex = 0, prv_index = 0, num_segments = 0;

		for (int i = 0; i < N; ++i) {
			if (A[i] <= N) freq[A[i]]++;
			while (freq[cur_mex]) cur_mex++;

			if (cur_mex >= x) {
				num_segments += 1;
				cur_mex = 0;

				for (int j = prv_index; j <= i; ++j)
					if (A[j] <= N) freq[A[j]]--;
				prv_index = i + 1;
			}
		}

		return num_segments >= K;
	};

	int l = 0, r = N + 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;

		if (possible(mid))
			l = mid;
		else
			r = mid;
	}
	cout << l << '\n';
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