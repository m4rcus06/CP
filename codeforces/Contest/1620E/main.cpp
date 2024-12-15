#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif

//y -> z
//x -> y

//id[2] = id[1]
//id[1] = id[3]

//1 2
//2 1 3
//2 2 1
const int L = (int) 5e5;

struct ops {
    int t, x, y;
};

void solve() {
    vector <int> id(L + 1, 0);
    iota(id.begin(), id.end(), 0);

    int q; cin >> q;
    vector <ops> queries(q);
    for (int i = 0; i < q; ++i) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            queries[i] = {t, x, 0};
        } else {
            int x, y; cin >> x >> y;
            queries[i] = {t, x, y};
        }
    }

    // function <int(int)> find = [&](int x) {
    //     return (x == id[x] ? x : id[x] = find(id[x]));
    // };

    vector <int> ans;
    for (int i = q - 1; i >= 0; --i) {
        if (queries[i].t == 2) {
            int x = queries[i].x, y = queries[i].y;
            id[x] = id[y];
        } else {
            int x = queries[i].x;
            ans.push_back(id[x]);
        }
    }
    reverse(ans.begin(), ans.end());

    for (int i = 0; i < (int) ans.size(); ++i) {
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