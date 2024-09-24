/* https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/B */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

int n, k;
vector <ll> a;

bool good(ll mid) {
    int cnt = 0;
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > mid) return false;

        if (sum + a[i] > mid) {
            sum = 0;
            ++cnt;
        }
        sum += a[i];
    }

    if (sum) ++cnt;

    return cnt <= k;
}

void solve() {
    cin >> n >> k;

    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    ll l = 0, r = 1;

    while (!good(r)) r *= 2;

    while (r - l > 1) {
        ll mid = (l + r) / 2;

        if (good(mid)) r = mid;
        else l = mid;
    }

    cout << r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
