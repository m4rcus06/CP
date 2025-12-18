#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const long long INF = lli(1e18) + 88;
const int N = int(5e5) + 5;

int n, d;
long long x[N];
int type[N];

long long t[4 * N], lazy[4 * N];
void push(int x, int lhs, int rhs) {
    if (lazy[x] == 0) return;
    int mid = (lhs + rhs) / 2;

    t[2 * x] += 1LL * (mid - lhs + 1) * lazy[x];
    t[2 * x + 1] += 1LL * (rhs - mid) * lazy[x];
    lazy[2 * x] += lazy[x];
    lazy[2 * x + 1] += lazy[x];
    lazy[x] = 0;
}

void update(int x, int lhs, int rhs, int l, int r, int v) {
    if (lhs > r || rhs < l) return;
    if (lhs >= l && rhs <= r) {
        t[x] += 1LL * (rhs - lhs + 1) * v;
        lazy[x] += v;
        return;
    }

    int mid = (lhs + rhs) >> 1;
    push(x, lhs, rhs);
    update(2 * x, lhs, mid, l, r, v);
    update(2 * x + 1, mid + 1, rhs, l, r, v);
    t[x] = t[2 * x] + t[2 * x + 1];
}

long long query(int x, int lhs, int rhs, int l, int r) {
    if (lhs > r || rhs < l) return 0;
    if (lhs >= l && rhs <= r) return t[x];

    int mid = (lhs + rhs) >> 1;
    push(x, lhs, rhs);
    return query(2 * x, lhs, mid, l, r) + query(2 * x + 1, mid + 1, rhs, l, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> type[i];
    }

    vector <long long> pos = {-INF};
    for (int i = 1; i <= n; ++i) {
        if (type[i] == 1) pos.push_back(x[i]);
    }
    int nn = pos.size() - 1;

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (type[i] == 0) {
            int it = lower_bound(pos.begin(), pos.end(), x[i]) - pos.begin();
            update(1, 1, nn, 1, it - 1, 1);
        } else {
            int it = lower_bound(pos.begin(), pos.end(), x[i] - d) - pos.begin();
            int e = lower_bound(pos.begin(), pos.end(), x[i]) - pos.begin() - 1;
            ans += query(1, 1, nn, it, e);
        }
    }

    cout << ans << '\n';

	return 0;
}
