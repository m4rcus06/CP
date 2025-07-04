#include <bits/stdc++.h>
using namespace std;
using lli = long long;

/*How to use:
    Tvector <int, 2> g(n); //graph
    Tvector <int, 2> f(n, k, 2) = f[n][k][2]
*/
template <class Tp, int D = 1>
struct Tvector : public vector<Tvector<Tp, D - 1>> {
    template <class... Args>
    Tvector(int n = 0, Args... args) : vector<Tvector<Tp, D - 1>>(n, Tvector<Tp, D - 1>(args...)) {}
};

template <class Tp>
struct Tvector<Tp, 1> : public vector<Tp> {
    Tvector(int n = 0, Tp val = Tp()) : vector<Tp>(n, val) {}
};

#ifdef LOCAL
#include </home/marcus06/mycp/Library/debug.h>
#else
#define debug(...) 
#endif

void solve() {
    int N;
    cin >> N;

    vector <int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        --A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
        --B[i];
    }

    Tvector <int, 2> pos(2, N, -1);
    int p = 0, ans = 0;
    for (int i = N - 1; i >= 0; --i) {
        bool found = false;
        if (A[i] == B[i]) found = true;
        if (pos[p][B[i]] != -1 || pos[p ^ 1][B[i]] > i + 1) found = true;
        if (pos[p ^ 1][A[i]] != -1 || pos[p][A[i]] > i + 1) found = true;
        
        if (pos[p][A[i]] == -1) pos[p][A[i]] = i;
        if (pos[p ^ 1][B[i]] == -1) pos[p ^ 1][B[i]] = i;
        p ^= 1;

        if (found) {
            ans = i + 1;
            break;
        }
    }

    cout << ans << '\n';
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