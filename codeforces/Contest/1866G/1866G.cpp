#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;
 
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int N; cin >> N;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector <int> D(N);
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }

    vector <int> l(N), r(N);
    for (int i = 0; i < N; ++i) {
        l[i] = max(0, i - D[i]);
        r[i] = min(N - 1, i + D[i]);
    }

    vector <vector <int>> at(N);
    for (int i = 0; i < N; ++i) {
        at[l[i]].push_back(i);
    }

    auto P = [&](int x) -> bool {
        priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> Q;
        for (int i = 0; i < N; ++i) {
            for (int p: at[i]) {
                if(A[p] > 0) Q.push({r[p], A[p]});
            }

            int cap = x;
            while (!Q.empty() && cap > 0) {
                auto cur = Q.top(); Q.pop();
                int r_bound = cur.first;
                int v = cur.second;

                if (r_bound < i) return false;

                int mn = min(cap, v);
                v -= mn;
                cap -= mn;

                if (v > 0) Q.push({r_bound, v});
            }
        }

        return Q.empty();
    };

    int L = -1, R = *max_element(A.begin(), A.end());
    while (R - L > 1) {
        int MID = (L + R) / 2;

        if (P(MID)) R = MID;
        else L = MID;
    }

    cout << R << '\n';
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
