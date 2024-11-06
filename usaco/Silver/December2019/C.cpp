#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;
 
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int MAXN = (int) 1e5;

int N, Q;
string S;

vector <int> g[MAXN];
int label[MAXN];

int cnt = 0;
void DFS(int u, int parent) {
    label[u] = cnt;
    for (int v: g[u]) {
        if (v != parent) {
            if (S[u] == S[v]) DFS(v, u);
        }
    }
}

void solve() {
    cin >> N >> Q >> S;
    for (int i = 0; i + 1 < N; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(label, -1, sizeof label);
    for (int i = 0; i < N; ++i) {
        if (label[i] == -1) {
            cnt++;
            DFS(i, i);
        }
    }

    string ans;
    while (Q--) {
        int u, v;
        char t;
        cin >> u >> v >> t;
        --u, --v;

        if (S[u] != t && label[u] == label[v]) ans.push_back('0');
        else ans.push_back('1');
    }

    cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
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

