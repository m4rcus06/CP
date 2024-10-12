#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int L = 2520;

int cache[18][L][L + 1];

int lcm (int a, int b) {
    return a * b / __gcd(a, b);
}

int f(string &S, int idx, int lead, int tight, int LCM, int MOD) {
    if (idx >= (int) S.size()) {
        if (!lead && MOD % LCM == 0) {
            return 1;
        }
        return 0;
    }
    
    int &res = cache[idx][LCM][MOD];
    if (cache[idx][LCM][MOD] != -1) return res;
    res = 0;

    int l = (lead ? 0 : 1);
    int r = (tight ? S[idx] - '0' : 9);
    for (int x = l; x <= r; ++x) {
        int n_LCM = (x == 0 ? LCM : lcm(LCM, x));
        int n_MOD = (MOD * 10 + x) % L;
        int n_tight = tight & (x == r);
        int n_lead = lead & (x == 0);

        res += f(S, idx + 1, n_lead, n_tight, n_LCM, n_MOD);
    }

    return res;
}
 
void solve() {
    string a, b;
    cin >> a >> b;

    memset(cache, -1, sizeof cache);

    cout << f(b, 0, 1, 1, 1, 0) - f(a, 0, 1, 1, 1, 0) << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
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

