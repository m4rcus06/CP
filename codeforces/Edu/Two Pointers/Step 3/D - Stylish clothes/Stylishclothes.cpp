/* https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/D */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;
const int inf = 1e9;

void solve() {
    vector <pair<int, int>> a;
    for (int i = 0; i < 4; ++i) {
        int n; cin >> n;
        for (int j = 1; j <= n; ++j) {
            int x; cin >> x;
            a.push_back({x, i});
        }
    }

    sort(a.begin(), a.end());

    queue <int> q[4];
    int sz = a.size();
    int mn = inf, cnt = 0;
    vector<int> res(4);

    for (int l = 0, r = 0; r < sz; ++r) {
        q[a[r].second].push(a[r].first);
        if (q[a[r].second].size() == 1) ++cnt;

        while (cnt > 3) {
            if (a[r].first - a[l].first < mn) {
                mn = a[r].first - a[l].first;
                for (int i = 0; i < 4; ++i) res[i] = q[i].front();
            }
            q[a[l].second].pop();
            if (q[a[l].second].empty()) cnt--;
            ++l;
        }

    }

    for (int i = 0; i < 4; ++i) cout << res[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
