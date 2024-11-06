#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;
 
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int N = 3005;

int n, k;
int arr[N][N];
int S[N][N];
int TL[N][N], TR[N][N], BL[N][N], BR[N][N];

void buildS() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + arr[i][j];
        }
    }
}

void buildTL() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            TL[i][j] = TL[i - 1][j - 1] + TL[i - 1][j] + arr[i][j];
            if (i > 1) TL[i][j] -= TL[i - 2][j - 1];
        }
    }
}

void buildTR() {
    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= 1; --j) {
            TR[i][j] = TR[i - 1][j + 1] + TR[i - 1][j] + arr[i][j];
            if (i > 1) TR[i][j] -= TR[i - 2][j + 1];
        }
    }
}

void buildBL() {
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            BL[i][j] = BL[i + 1][j - 1] + BL[i + 1][j] + arr[i][j];
            if (i + 2 <= n) BL[i][j] -= BL[i + 2][j - 1];
        }
    }
}

void buildBR() {
    for (int i = n; i >= 1; --i) {
        for (int j = n; j >= 1; --j) {
            BR[i][j] = BR[i + 1][j + 1] + BR[i + 1][j] + arr[i][j];
            if (i + 2 <= n) BR[i][j] -= BR[i + 2][j + 1];
        }
    }
}

int rec_sum(int x, int y, int u, int v) {
    return S[u][v] - S[x - 1][v] - S[u][y - 1] + S[x - 1][y - 1];
}

int query (int i, int j) {
    lli ans = 0;
    ans += BL[i - k][j] - BL[i][j - k] - rec_sum(i, j - k + 1, n, j);
    ans += BR[i - k][j] - BR[i][j + k] - rec_sum(i, j, n, j + k - 1);
    ans -= rec_sum(i - k, j, i - 1, j);

    ans += TL[i + k][j] - TL[i][j - k] - rec_sum(1, j - k + 1, i, j);
    ans += TR[i + k][j] - TR[i][j + k] - rec_sum(1, j, i, j + k - 1);
    ans -= rec_sum(i + 1, j, i + k, j);

    ans += rec_sum(i, j - k, i, j + k);
    return ans;
}
 
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[k + i][k + j];
        }
    }

    int normal_size = n;

    n += 2 * k;
    buildS();
    buildTL();
    buildTR();
    buildBL();
    buildBR();

    for (int i = 1; i <= normal_size; ++i) {
        for (int j = 1; j <= normal_size; ++j) {
            cout << query(k + i, k + j) << ' ';
        }
        cout << '\n';
    }
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

