#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int N, M; cin >> N >> M;
    vector <int> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }
    sort (T.begin(), T.end());

    vector <int> l(M), r(M);
    for (int i = 0; i < M; ++i) {
        cin >> l[i] >> r[i];
    }

    vector <int> ord(M);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){ return l[i] < l[j];});

    int ans = 0;
    multiset <int> mset;
    int j = 0;
    for (int i = 0; i < M; ++i) {
        int idx = ord[i];

        if (j < N && l[idx] > T[j]) {
            while (!mset.empty() && j < N) {
                if (T[j] >= l[idx]) break;

                if (*mset.begin() >= T[j]) {
                    ++ans;
                    j++;
                }
                mset.erase(mset.begin());
            }
        }

        while (j < N && T[j] < l[idx]) j++;
        mset.insert(r[idx]);
    }

    while (!mset.empty() && j < N) {
        if (*mset.begin() >= T[j]) {
            ++ans;
            j++;
        }
        mset.erase(mset.begin());
    }

    cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen ("helpcross.in", "r", stdin);
    freopen ("helpcross.out", "w", stdout);
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

