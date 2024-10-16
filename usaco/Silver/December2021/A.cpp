#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

int64_t get_ans (int L, int R, vector <int64_t> &p, vector <int64_t> &v) {
    if (L > R) return 0;
    int sz = (int) v.size();

    int64_t res = 0;
    vector <int64_t> S(sz + 1, 0);
    for (int i = 0; i < sz; ++i) {
        S[i + 1] = S[i] + v[i];
    }

    if (L == (int) -2e9 || R == (int) 2e9) return S[sz];

    for (int i = 0; i < sz; ++i) {
        int64_t a = 1LL * (L + p[i]) / 2;
        int64_t b = 1LL * (R + p[i]) / 2;

        int l_idx = upper_bound(p.begin(), p.end(), a) - p.begin() + 1;
        int r_idx = lower_bound(p.begin(), p.end(), b) - p.begin();

        if (l_idx <= r_idx) res = max(res, S[r_idx] - S[l_idx - 1]);
    }

    return res;
}

void solve() {
    int K, M, N; cin >> K >> M >> N;
    vector <int> p(K), t(K);
    for (int i = 0; i < K; ++i) {
        cin >> p[i] >> t[i];
    }

    vector <int> f(M);
    for (int i = 0; i < M; ++i) {
        cin >> f[i];
    }
    sort (f.begin(), f.end());

    //position, value, type;
    vector <array <int, 3>> A;
    for (int i = 0; i < K; ++i) {
        A.push_back({p[i], t[i], 1});
    }

    for (int i = 0; i < M; ++i) {
        A.push_back({f[i], 0, 0});
    }
    A.push_back({(int) -2e9, 0, 0});
    A.push_back({(int) 2e9, 0, 0});
    sort (A.begin(), A.end());
    
    vector <int64_t> cur_p, cur_v, best_value;
    for (int i = 0; i + 1 < (int) A.size(); ++i) {
        if (A[i][2] == 0) {
            cur_p.clear();
            cur_v.clear();

            int64_t range_sum = 0;
            int j = i + 1;
            while (A[j][2] == 1) {
                cur_p.push_back(A[j][0]);
                cur_v.push_back(A[j][1]);

                range_sum += A[j][1];
                j++;
            }
            
            int L = A[i][0], R = A[j][0];
            int64_t v = get_ans(L, R, cur_p, cur_v);
            best_value.push_back(v);

            //if we choose to place another cow in this interval
            //we can get every patch in this, so add range_sum - v as a second choice
            best_value.push_back(range_sum - v);

            i = j - 1;
        }
    }
    sort (best_value.begin(), best_value.end());

    int cnt = 1;
    int64_t ans = 0;
    while (cnt <= N) {
        ans += best_value.back();
        best_value.pop_back();
        ++cnt;
    }

    cout << ans << '\n';
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

