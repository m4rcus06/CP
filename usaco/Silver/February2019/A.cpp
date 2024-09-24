#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int min_moves = INT_MAX;
    if ((A[N - 1] - A[1] + 1 == N - 1 && A[1] - A[0] > 2) ||
        (A[N - 2] - A[0] + 1 == N - 1 && A[N - 1] - A[N - 2] > 2)) {
        
        min_moves = 2;
    } else {
        for (int i = 0, j = 0; i < N; ++i) {
            while (A[i] - A[j] + 1 >= N) {
                min_moves = min(min_moves, N - (i - j + 1) + (A[i] - A[j] + 1 != N));
                j++;
            }
        }
    }

    int gaps_sum = 0;
    for (int i = 1; i < N; ++i) {
        gaps_sum += A[i] - A[i - 1] - 1;
    }

    int max_moves = max(gaps_sum - (A[1] - A[0] - 1), gaps_sum - (A[N - 1] - A[N - 2] - 1));

    cout << min_moves << '\n' << max_moves << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen ("herding.in", "r", stdin);
    freopen ("herding.out", "w", stdout);
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

