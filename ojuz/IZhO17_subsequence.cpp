#include <bits/stdc++.h>
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

using namespace std;
using lli = long long;

/*How to use:
    Vec <int, 2> g(n); //graph
    Vec <int, 3> f(n, k, 2) = f[n][k][2]
*/
template <class Tp, int D = 1>
struct Vec : public vector<Vec<Tp, D - 1>> {
    static_assert(D >= 1, "Dimension must be positive");
    template <class... Args>
    Vec(int n = 0, Args... args) : vector<Vec<Tp, D - 1>>(n, Vec<Tp, D - 1>(args...)) {}
};
 
template <class Tp>
struct Vec<Tp, 1> : public vector<Tp> {
    Vec(int n = 0, Tp val = Tp()) : vector<Tp>(n, val) {}
};

int bit_count(int x) {
    return __builtin_popcount(x);
}

void solve() {
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector <int> k(n);
    for (int i = 0; i < n; ++i) cin >> k[i];

    //best[mask][k]: maximum len overall x such that bit_count(x & mask) == k
    Vec <int, 3> best(1 << 10, 1 << 10, 11, -1);
    vector <int> f(n, 1), trace(n, -1);
    for (int i = 0; i < n; ++i) {
        int x = a[i];

        int low = x & (MASK(10) - 1);
        int high = x >> 10;
        for (int mask = 0; mask < (1 << 10); ++mask) {
            int has = bit_count(high & mask);
            if (has > k[i] || bit_count(low) < k[i] - has) continue; 

            int last = best[mask][low][k[i] - has];
            if (last != -1 && f[i] < f[last] + 1) {
                f[i] = f[last] + 1;
                trace[i] = last;
            }
        }

        for (int mask = 0; mask < (1 << 10); ++mask) {
            int cnt = bit_count(low & mask);
            auto &idx = best[high][mask][cnt];
            if (idx == -1 || f[idx] < f[i]) {
                idx = i;
            }
        }
    }

    
    int p = max_element(f.begin(), f.end()) - f.begin();
    vector <int> ans;
    for (int i = p; i != -1; i = trace[i]) ans.push_back(i);
    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (auto x: ans) cout << x + 1 << ' ';
    cout << '\n';
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

