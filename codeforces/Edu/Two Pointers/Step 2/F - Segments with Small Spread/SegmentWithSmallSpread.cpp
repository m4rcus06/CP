/* https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F */
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

struct qStack {
    vector <ll> s, maxS = {LLONG_MIN}, minS = {LLONG_MAX};

    void push(ll x) {
        s.push_back(x);
        maxS.push_back(max(maxS.back(), x));
        minS.push_back(min(minS.back(), x));
    }
    ll pop() {
        ll res = s.back();
        s.pop_back();
        maxS.pop_back();
        minS.pop_back();

        return res;
    }

    bool empty() {
        return s.empty();
    }

    ll mn() {
        return minS.back();
    }

    ll mx() {
        return maxS.back();
    }
};

qStack s1, s2;
ll n, k;

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

bool ok() {
    ll mn = min(s1.mn(), s2.mn());
    ll mx = max(s1.mx(), s2.mx());

    return (mx - mn <= k);
}

void solve() {
    cin >> n >> k;
    vector <ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    ll res = 0;
    for (ll l = 1, r = 1; r <= n; ++r) {
        add(a[r]);
        while (!ok()) {
            remove(a[l++]);
        }
        res += r - l + 1;
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
