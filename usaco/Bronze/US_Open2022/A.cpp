#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "../Library/debug.h"
#else
#define debug(...)
#endif

/*
 * Only reverse even length prefixes
 * Analysis:
 * - Let's mark 'G' = 1 if it is at even position, -1 otherwise in array named V.
 *   (which mean change in number of 'G' at even-numbered positon)
 * - Since we can only reverse even length prefixes, so let's group V[i] and V[i + 1], put in array A for easier calculation
 * - Now our task is to make the whole array A contain only '-1'
 * */

int calc (vector<int> &A) {
    if (A.empty()) return 0;

    bool first_met = (A[0] == 1);
    int res = 0;
    for (int i = 0, continous = 0; i < (int) A.size(); ++i) {
        if (A[i] == 1) {
            if (continous) continue;

            if (first_met) {
                res += 1;
                first_met = false;
            } else {
                res += 2;
            }

            continous = 1;
        } else continous = 0;
    }
    return res;
}

void solve() {
    int N;
    string S;
    cin >> N >> S;
    S = '$' + S;

    vector<int> v(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        v[i] = (S[i] == 'G');
        if (i % 2 == 0) v[i] *= -1;
    }

    vector<int> A;
    for (int i = 1; i + 1 <= N; i += 2) {
        if (v[i] + v[i + 1] == 0) continue;
        A.push_back(v[i] + v[i + 1]);
    }
    
    int ans = calc(A);
    cout << ans << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = chrono::high_resolution_clock::now();
#endif
 
    int tt = 1;
    while (tt--) {
        solve();
    }
 
#ifdef LOCAL
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
#endif
 
    return 0;
}

