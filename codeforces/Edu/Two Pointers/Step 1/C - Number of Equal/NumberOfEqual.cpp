/*https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C*/
#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define endl '\n'
#define st first
#define nd second

using namespace std;
const ll maxN = 1e5;
ll n, m, a[maxN + 2], b[maxN + 2];

void solve()
{
	cin >> n >> m;
	for (ll i = 1; i <= n; ++i) cin >> a[i];
	for (ll i = 1; i <= m; ++i) cin >> b[i];

	a[n + 1] = 1e12;
	b[m + 1] = 1e13;

	ll res = 0;
	ll i = 1, j = 1;
	ll cnt_A = 1, cnt_B = 1;
	while (i <= n || j <= m)
	{

		while (a[i] == a[i + 1] && i <= n)
		{
			cnt_A++;
			i++;
		}

		while (b[j] == b[j + 1] && j <= m)
		{
			cnt_B++;
			j++;
		}

		if (a[i] == b[j])
		{
			res += cnt_A * cnt_B;
			cnt_A = 1, cnt_B = 1;
			i++, j++;
		}
		else if (j > m || (i <= n && a[i] < b[j]))
		{
			i++;
			cnt_A = 1;
		}
		else
		{
			j++;
			cnt_B = 1;
		}
	}

	cout << res;
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
