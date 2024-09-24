#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int N; cin >> N;
    vector <int> l(N), r(N);
    for (int i = 0; i < N; ++i) {
        cin >> l[i] >> r[i];
    }

    vector <int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        if (l[i] == l[j]) return r[i] < r[j];
        return l[i] < l[j];
    });
    
    multiset <int> mset;
    int at = 0;
    for (int i = 0; i < N; ++i) {
        at = max(at, l[ord[i]]);
        
        mset.insert(r[ord[i]]);
        while (!mset.empty()) {
            if (i + 1 < N && at >= l[ord[i + 1]]) break;
            if (*mset.begin() < at) {
                cout << "NO" << '\n';
                return;
            }

            mset.erase(mset.begin());
            ++at;
        }
    }

    cout << "YES" << '\n';
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
