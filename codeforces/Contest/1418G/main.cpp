#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif

namespace std {
 
template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
    static_assert(D >= 1, "Dimension must be positive");
    template <typename... Args>
    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
 
template <typename T>
struct Vec<1, T> : public vector<T> {
    Vec(int n = 0, T val = T()) : std::vector<T>(n, val) {}
};
}

const int N = 5e5 + 5;
const int mod[] = {1000000007, 998244353};

int n, a[N], cnt[N], nxt[N];
int pw[2][N];
array <int, 2> H[N];

static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

size_t f(uint64_t x) {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
}

uint64_t base;
void init() {
    base = f(12345);
    pw[0][0] = pw[1][0] = 1;
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j <= n; ++j) {
            pw[i][j] = (1LL * pw[i][j - 1] * base) % mod[i];
        }
    }

    for (int i = n, j = n; i > 0; --i) {
        cnt[a[i]] += 1;
        while (cnt[a[i]] > 3) {
            cnt[a[j]] -= 1;
            j--;
        }
        nxt[i] = max(i, j);
    }

    memset(cnt, 0, sizeof cnt);

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            H[i][j] = (1LL * H[i - 1][j] - 1LL * cnt[a[i]] * pw[j][a[i]]) % mod[j];
            while (H[i][j] < 0) H[i][j] += mod[j];
        }
        cnt[a[i]] = (cnt[a[i]] + 1) % 3;
        for (int j = 0; j < 2; ++j) {
            H[i][j] = (1LL * H[i][j] + 1LL * cnt[a[i]] * pw[j][a[i]]) % mod[j];
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    init();

    map <array <int, 2>, vector <int>> m;
    m[H[0]].push_back(0);
    for (int i = 1; i <= n; ++i) {
        m[H[i]].push_back(i);
    }

    lli ans = 0;
    for (auto &itr: m) {
        auto vec = itr.second;
        for (int i = 0, j = 0; i < (int) vec.size(); ++i) {
            while (j < i && nxt[vec[j] + 1] < vec[i]) j++;
            ans += i - j;
        }
    }

    cout << ans << '\n';
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