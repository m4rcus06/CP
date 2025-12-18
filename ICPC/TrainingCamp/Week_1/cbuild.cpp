#include <bits/stdc++.h>
using namespace std;
using lli = long long;

/*How to use:
    Tvector <int, 2> g(n); //graph
    Tvector <int, 3> f(n, k, 2) = f[n][k][2]
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
#include </home/marcus06/CP/Library/debug.h>
#else
#define debug(...) 
#endif

const lli INF = lli(1e15);

void solve() {
    int n;
    cin >> n;
    vector <lli> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    auto nxt = [&](int i) {
        return (i + 1) % n;
    };

    vector <lli> f(n);
    auto calc = [&](lli dest, lli add) -> lli{
        f = vector <lli>(n);
        vector h = a;
        f[0] = add;
        h[0] += add;
        h[1] += 2 * add;
        for (int i = 1; i < n; ++i) {
            f[i] = dest - h[i];
            if (f[i] > INF) {
                if ((n - i - 1) & 1) return -INF;
                return INF;
            }
            if (f[i] < -INF) {
                if ((n - i - 1) & 1) return INF;
                return -INF;
            }
            h[i] += f[i];
            h[nxt(i)] += 2 * f[i];
        }
        return h[0];
    };

    lli mx = *max_element(a.begin(), a.end());
    auto possible = [&](lli dest) {
        if (dest < mx) return false;

        lli l = -1, r = dest;
        while (r - l > 1) {
            lli mid = (l + r) >> 1;
            bool ok = ((n & 1) ? (calc(dest, mid) >= dest) : (calc(dest, mid) <= dest));
            if (ok) r = mid;
            else l = mid;
        }
        return calc(dest, r) == dest;
    };

    lli l = -1, r = 2 * mx / 3 + 1, ans = -1;
    while (r - l > 1) {
        lli mid = (l + r) >> 1;
        bool ok = false;
        for (int i = 0; i < 3; ++i) {
            if (possible(3 * mid + i)) {
                ok = true;
                ans = 3 * mid + i;
                break;
            }
        }
        if (ok) r = mid;
        else l = mid;
    }

    if (ans == -1) {
        cout << ans << '\n';
        return;
    }
    possible(ans);

    lli mn = *min_element(f.begin(), f.end());
    for (auto &x: f) x -= mn;

    cout << accumulate(f.begin(), f.end(), 0LL) << '\n';
    for (auto x: f) cout << x << ' ';
    cout << '\n';
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