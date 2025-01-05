#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int mxN = (int) 1e5 + 5;
const int mxV = (int) 1e6 + 5;

int N, Q, a[mxN];
int x[mxN], v[mxN];

void subtask_1() {
    vector <int> b;
    for (int i = 1; i <= Q; ++i) {
        a[x[i]] = v[i];
        for (int j = 1; j <= N; ++j) {
            b.push_back(a[j]);
        }
        sort(b.begin(), b.end(), greater<int>());

        lli ans = 0;
        for (int j = 0, t = 1; j < N; ++j) {
            ans += t * b[j];
            t ^= 1;
        }
        b.clear();
        cout << ans << '\n';
    }
}

void subtask_2() {
    vector <int> cnt(101, 0);
    for (int i = 1; i <= N; ++i) {
        cnt[a[i]] += 1;
    }

    for (int i = 1; i <= Q; ++i) {
        cnt[a[x[i]]] -= 1;
        a[x[i]] = v[i];
        cnt[a[x[i]]] += 1;

        int t = 1;
        lli ans = 0;
        for (lli k = 100; k >= 1; --k) {
            if (cnt[k] > 0) {
                ans += k * ((cnt[k] + t) / 2);
                t ^= (cnt[k] & 1);
            }
        }
        cout << ans << '\n';
    }
}

struct LazySegmentTree {
};

void subtask_3() {
    cout << "too lazy lmao";
}


void solve() {
    cin >> N >> Q;
    int max_a = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }

    int max_v = 0;
    for (int i = 1; i <= Q; ++i) {
        cin >> x[i] >> v[i];
        max_v = max(max_v, v[i]);
    }

    if (N <= 1000 && Q <= 1000) subtask_1();
    else if (max_a <= 100 && max_v <= 100) subtask_2();
    else subtask_3();
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("GIFTGAME.INP", "r", stdin);
    freopen("GIFTGAME.OUT", "w", stdout);
#endif

    int tt = 1;
    while (tt--) {
        solve();
    }

#ifdef LOCAL
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
#endif
    return 0;
}