/* https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/A */
#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define endl '\n'
#define st first
#define nd second

using namespace std;
const ll maxN = 1e5;
ll n, m, a[maxN + 1], b[maxN + 1], merged[2 * maxN + 1];

void solve()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) cin >> a[i];
    for (ll i = 1; i <= m; ++i) cin >> b[i];

    ll i = 1, j = 1;
    ll cnt = 0;
    while (i <= n || j <= m)
    {
        if (j > m || (i <= n && a[i] <= b[j]))
        {
            merged[++cnt] = a[i];
            ++i;
        }
        else
        {
            merged[++cnt] = b[j];
            ++j;
        }
    }
    for (ll i = 1; i <= cnt; ++i) cout << merged[i] << " ";

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t = 1;
    while (t--)
    {
        solve();
    }

    //cerr << "\n\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";

    return 0;
}
