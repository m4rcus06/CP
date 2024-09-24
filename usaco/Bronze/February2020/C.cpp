#include <bits/stdc++.h>

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    using namespace std;

    int N, K; cin >> N >> K;
    vector<vector<int>> A(2, vector<int>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> nxt(N, vector<int>(2, -1));
    for (int j = 0; j < 2; ++j) {
       for (int L = A[j][0], R = A[j][1]; L < R; ++L, --R) {
           nxt[L - 1][j] = R - 1;
           nxt[R - 1][j] = L - 1;
       }
    }

    function<int(int, int)> dfs = [&](int u, int p) {
        int res = 1;
        for (int i = 0; i < 2; ++i) {
            int v = nxt[u][i];
            if (i > 0 && v == nxt[u][i - 1]) continue;
            if (v == -1 || v == p) continue;
            res += dfs(v, u);
        }
        return res;
    };

    vector<int> component_size(N);
    for (int i = 0; i < N; ++i) {
        component_size[i] = dfs(i, -1);
    }

    vector<int> ans(N);
    for (int i = 0; i < N; ++i) {
        if (nxt[i][0] == nxt[i][1]) {
            //special case where these two nodes doesn't change position
            ans[i] = i + 1;
            continue;
        }

        int cnt = 0;
        int cur_sz = 0;
        int cur = i;
        vector<int> notVis(N, 1);
        while (cur_sz != component_size[i]) {
           for (int j = 0; j < 2; ++j) {
               if (nxt[cur][j] != -1) {
                   cur = nxt[cur][j];
               }
           }
           cur_sz += notVis[cur];
           notVis[cur] = 0;
           ++cnt;
        }

        int nK = K % cnt;
        int pos = i;
        while (nK > 0) {
            for (int j = 0; j < 2; ++j) {
                if (nxt[pos][j] != -1){
                    pos = nxt[pos][j];
                }
            }
            nK--;
        }
        ans[pos] = i + 1;
    }

    for (int &a: ans){
        cout << a << '\n';
    }
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen ("swap.in", "r", stdin);
    freopen ("swap.out", "w", stdout);
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

