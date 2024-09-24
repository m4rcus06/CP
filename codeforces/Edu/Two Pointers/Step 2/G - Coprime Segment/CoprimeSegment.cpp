/* https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/G */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

struct gcd_Queue {
    vector <ll> s, s1 = {0};

    void push(ll x) {
        s.push_back(x);
        s1.push_back(__gcd(s1.back(), x));
    }

    ll pop() {
        ll ret = s.back();

        s.pop_back();
        s1.pop_back();

        return ret;
    }

    ll size() {
        return s.size();
    }

    bool empty() {
        return s.empty();
    }

    ll gcd() {
        return s1.back();
    }

};

gcd_Queue s1, s2;

void add(ll x) {
    s2.push(x);
}

void remove(ll x) {
    if (s1.empty()) {
        while (!s2.empty()) {
            s1.push(s2.pop());
        }
    }

    s1.pop();
}

bool good() {
    ll x = s1.gcd();
    ll y = s2.gcd();

    return __gcd(x, y) == 1;
}

void solve() {
    ll n; cin >> n;

    vector <ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    ll res = n + 1;

    for (ll l = 1, r = 1; r <= n; ++r) {
        add(a[r]);

        while (good()) {
            res = min(res, r - l + 1);
            remove(a[l]);
            ++l;
        }
    }

    if (res == n + 1) cout << -1;
    else cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t = 1;
    while (t--) {
        solve();
    }

    return 0;
}