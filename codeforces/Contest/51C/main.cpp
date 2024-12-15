#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif

const double eps = 1e-9;
 
void solve() {
    int N; cin >> N;
    vector <double> x(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());

    array <double, 3> ans;
    auto isGood = [&](double dist) -> bool {
        int cnt = 0;
        array <double, 3> cur_ans;
        for (int i = 0; i < N;) {
            if (cnt >= 3) return false;

            ++cnt;
            cur_ans[cnt - 1] = x[i] + dist;
            i = upper_bound(x.begin(), x.end(), x[i] + 2.0 * dist) - x.begin();
        }

        if (cnt <= 3) {
            ans = cur_ans;
            return true;
        }
        return false;
    };

    double l = 0, r = x.back();
    for (int iter = 0; iter < 60; ++iter) {
        double mid = (l + r) / 2.0;

        if (isGood(mid)) r = mid;
        else l = mid;
    }
    ans.back() = x.back() - r;

    cout << setprecision(10) << fixed;
    cout << r << '\n';
    for (int i = 0; i < 3; ++i) {
        cout << ans[i] << ' ';
    }
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