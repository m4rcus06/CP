#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    ifstream inp("cardgame.in");
    ofstream out("cardgame.out");

    int N; inp >> N;
    vector <int> A(N);
    vector <int> used(2 * N + 1, 0); 
    for (int i = 0; i < N; ++i) {
        inp >> A[i];
        used[A[i]] = 1;
    }

    set <int> first_half;
    for (int i = 2 * N, cnt = 0; i >= 1; --i) {
        if (cnt == N / 2) break;

        if (used[i] == 0) {
            used[i] = 1;
            first_half.insert(i);
            ++cnt;
        }
    }

    set <int> second_half;
    for (int i = 1, cnt = 0; i <= 2 * N; ++i) {
        if (cnt == N / 2) break;

        if (used[i] == 0) {
            used[i] = 1;
            second_half.insert(i);
            ++cnt;
        }
    }

    int ans = 0;
    for (int i = 0; i < N / 2; ++i) {
        auto itr = first_half.lower_bound(A[i]);

        if (itr != first_half.end()) {
            ++ans;
            first_half.erase(itr);
        } else {
            first_half.erase(first_half.begin());
        }
    }

    for (int i = N / 2; i < N; ++i) {
        auto itr = second_half.lower_bound(A[i]);

        if (itr != second_half.begin()) itr = prev(itr);

        if (*itr < A[i]) ++ans;
        else itr = prev(second_half.end());

        second_half.erase(itr);
    }

    out << ans << '\n';
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

