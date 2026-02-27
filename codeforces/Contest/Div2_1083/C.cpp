#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
    int n;
    cin >> n;
    vector a(n, vector <int> ());
    for (int i = 0; i < n; ++i) {
        int l; cin >> l;
        a[i].resize(l);
        for (auto &x: a[i]) cin >> x;
    }

    //calc
    vector effect(n, vector <int> ());
    for (int i = 0; i < n; ++i) {
        auto aux = a[i];
        set <int> seen;
        while (!aux.empty()) {
            int v = aux.back(); aux.pop_back();
            if (seen.find(v) == seen.end()) effect[i].push_back(v);
            seen.insert(v);
        }
    }

    vector <int> ans;
    set <int> seen;
    int t = n;
    while (t--) {
        sort(effect.begin(), effect.end());
        auto vec = effect[0];

        for (auto x: vec) {
            if (seen.find(x) == seen.end()) ans.push_back(x);
            seen.insert(x);
        }
        

        effect.erase(effect.begin());
        for (auto &vec: effect) {
            vector <int> cur;
            for (auto v: vec) {
                if (seen.find(v) == seen.end()) cur.push_back(v);
            }
            vec = move(cur);
        }
    }

    for (auto x: ans) cout << x << ' ';
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