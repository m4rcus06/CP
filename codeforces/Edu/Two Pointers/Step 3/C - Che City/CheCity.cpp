/* https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/C */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

void solve() {
    ll n, fog;
    cin >> n >> fog;

    vector <ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    ll res = 0;
    for (ll l = 1, r = 1; r <= n; ++r) {

        while (a[r] - a[l] > fog) {
            res += n - r + 1;
            ++l;
        }
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
