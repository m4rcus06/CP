/* https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;

    vector <ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    int q; cin >> q;
    while (q--) {
        ll l, r; cin >> l >> r;
        int p = upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);

        cout << p << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
