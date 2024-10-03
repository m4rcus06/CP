#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int mod = 1e9 + 7;

void solve() {
    int N; cin >> N;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    auto F = [&](vector <int> X) -> vector <int> {
        int sz = (int) X.size();
        set <array <int, 3>> S;
        
        for (int i = 0; i + 1 < sz; ++i) {
            S.insert({X[i] + X[i + 1], i, i + 1});
        }

        vector <int> res;
        while ((int) res.size() < sz - 1) {
            auto cur = *S.begin();
            S.erase(S.begin());

            res.push_back(cur[0]);
            ++cur[2];
            if (cur[2] < sz) {
                cur[0] = X[cur[1]] + X[cur[2]];
                S.insert(cur);
            }
        }
            
        sort(res.begin(), res.end());
        return res;
    };

    int ans = 0;
    for (int len = N; len > 1; --len) {
        int mn = A[0];
        ans = 1LL * ((2LL * ans) % mod + mn) % mod;

        for (int &x : A) x -= mn;
        A = F(A);
    }

    ans = 1LL * ((2LL * ans) % mod + A[0]) % mod;
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

