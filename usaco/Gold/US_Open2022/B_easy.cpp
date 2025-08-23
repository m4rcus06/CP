#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#ifdef LOCAL
#include </home/marcus06/CP/Library/debug.h>
#else
#define debug(...) 
#endif

/*How to use:
  Tvector <int, 2> g(n); //graph
  Tvector <int, 3> f(n, k, 2) = f[n][k][2]
*/
template <class Tp, int D = 1>
struct Tvector : public vector<Tvector<Tp, D - 1>> {
  template <class... Args>
  Tvector(int n = 0, Args... args) : vector<Tvector<Tp, D - 1>>(n, Tvector<Tp, D - 1>(args...)) {}
};
 
template <class Tp>
struct Tvector<Tp, 1> : public vector<Tp> {
  Tvector(int n = 0, Tp val = Tp()) : vector<Tp>(n, val) {}
};

const int mod = int(1e9) + 7;

void add(int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

void sub(int &x, int y) {
    x -= y;
    if (x < 0) x += mod;
}

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    vector <int> ops_E, ops_B;
    for (auto x: s1) {
        if (x == '1') continue;
        if (x == '0') ops_E.clear();
        ops_E.push_back(0 + (x == '+'));
    }
    for (auto x: s2) {
        if (x == '1') continue;
        if (x == '0') ops_B.clear();
        ops_B.push_back(0 + (x == '+'));
    }

    int a = ops_E.size(), b = ops_B.size();
    Tvector <int, 2> f(a + 1, b + 1);
    for (int i = 0; i <= a; ++i) f[i][0] = 1;
    for (int i = 0; i <= b; ++i) f[0][i] = 1;

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            add(f[i][j], f[i - 1][j]);
            add(f[i][j], f[i][j - 1]);
            if (ops_E[i - 1] == ops_B[j - 1]) {
                sub(f[i][j], f[i - 1][j - 1]);
            }
        }
    }
    cout << f[a][b] << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif

    int tt = 1;
    cin >> tt;
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

