/* https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/H */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

void solve() {
    ll n, m, s, a, b;
    cin >> n >> m >> s >> a >> b;

    vector <pair<ll, ll>> g, h;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        g.push_back({x, a});
    }
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        h.push_back({x, b});
    }

    sort(g.begin(), g.end());
    sort(h.begin(), h.end());
    reverse(h.begin(), h.end());

    vector <pair<ll, ll>> f;
    for (int i = 0; i < n; ++i) f.push_back(g[i]);
    for (int i = 0; i < m; ++i ) f.push_back(h[i]);

    ll w = 0, v = 0, res = 0;
    for (int l = 0, r = 0; r < f.size(); ++r) {
        w += f[r].second;
        v += f[r].first;

        while (w > s) {
            w -= f[l].second;
            v -= f[l].first;
            ++l;
        }

        res = max(res, v);
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
