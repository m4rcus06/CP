#include <bits/stdc++.h>
using namespace std;

const int L = 2520;

vector <int> v;
int64_t cache[20][2][2][50][L + 5];

int lcm (int a, int b) {
    return a * b / __gcd(a, b);
}

void generate_LCM() {
    for (int mask = 0; mask < (1 << 9); ++mask) {
        int l = 1;
        for (int i = 0; i < 9; ++i) {
            if (mask >> i & 1) {
                l = lcm(l, i + 1);
            }
        }
        v.push_back(l);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int get_idx(int value) {
    return lower_bound(v.begin(), v.end(), value) - v.begin();
}

int64_t f(string &S, int idx, int lead, int tight, int LCM, int MOD) {
    if (idx >= (int) S.size()) {
        if (!lead && (MOD % LCM) == 0) {
            return 1;
        }
        return 0;
    }
    
    int LCM_idx = get_idx(LCM);
    int64_t &res = cache[idx][tight][lead][LCM_idx][MOD];
    if (cache[idx][tight][lead][LCM_idx][MOD] != -1) return res;
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
    long long a, b;
    cin >> a >> b;
    a -= 1;

    string L = to_string(a), R = to_string(b);

    generate_LCM();
    memset(cache, -1, sizeof cache);
    int64_t res = f(R, 0, 1, 1, 1, 0); 

    if (a > 0) {
        memset(cache, -1, sizeof cache);
        res -= f(L, 0, 1, 1, 1, 0);
    }

    cout << res << '\n';
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