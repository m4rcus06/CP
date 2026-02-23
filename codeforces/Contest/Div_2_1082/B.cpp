#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector f(n + 1, vector (2, vector <int> (2)));
    f[0][n & 1][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (f[i][j][k] == 0) continue;
                //try to match s[i]
                if (s[i] == 'a') {
                    if (j == 0) {
                        if (k == 0) {
                            f[i + 1][j ^ 1][k ^ 1] = 1;
                        } else {
                            f[i + 1][j ^ 1][k] = 1;
                        }
                    } else {
                        if (k == 0) {
                            f[i + 1][j ^ 1][k] = f[i + 1][j ^ 1][k ^ 1] = 1;
                        }
                    }
                } else if (s[i] == 'b') {
                    if (j == 0) {
                        if (k == 0) {
                            f[i + 1][j ^ 1][k] = 1;
                        } else {
                            f[i + 1][j ^ 1][k ^ 1] = 1;
                        }
                    } else {
                        if (k == 1) {
                            f[i + 1][j ^ 1][k] = f[i + 1][j ^ 1][k ^ 1] = 1;
                        }
                    }
                } else {
                    f[i + 1][j ^ 1][k] = f[i + 1][j ^ 1][k ^ 1] = 1;
                }
            }
        }
    }

    int ok = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) ok |= f[n][i][j];
    }

    cout << (ok ? "YES" : "NO") << '\n';
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