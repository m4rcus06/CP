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
    int N, Q;
    cin >> N >> Q;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector <lli> S(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        S[i + 1] = S[i] + A[i];
    }

    vector <int> p(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        p[i + 1] = p[i] ^ A[i];
    }   

    lli f = S[N] - p[N];
    while (Q--) {
        int l, r;
        cin >> l >> r;

        int l_ans = 1, r_ans = N;
        for (int i = 1; i <= N; ++i) {
            int L = i - 1, R = N;
            while (R - L > 1) {
                int M = (L + R) / 2;

                if (S[M] - S[i - 1] - (p[M] ^ p[i - 1]) == f) R = M;
                else L = M; 
            }

            if ((S[R] - S[i - 1] - (p[R] ^ p[i - 1]) == f && R - i < r_ans - l_ans)) {
                l_ans = i;
                r_ans = R;
            }
        }

        cout << l_ans << ' ' << r_ans << '\n';
    }
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