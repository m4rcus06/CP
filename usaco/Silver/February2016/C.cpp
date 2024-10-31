#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif

const int N = 105;

bool cache[N][N][N];

int x, y, k, m;
int ans = 1e9 + 7;

void DFS(int f, int s, int cnt) {
    if (cnt > k) return;
    ans = min(ans, abs(f + s - m));

    if(cache[f][s][cnt]) return;
    cache[f][s][cnt] = true;

    if (f == 0) DFS(x, s, cnt + 1);
    if (s == 0) DFS(f, y, cnt + 1);
    if (f != 0) DFS(0, s, cnt + 1);
    if (s != 0) DFS(f, 0, cnt + 1);

    int z1 = min(x - f, s);
    DFS(f + z1, s - z1, cnt + 1);

    int z2 = min(f, y - s);
    DFS(f - z2, s + z2, cnt + 1);
}
 
void solve() {
    cin >> x >> y >> k >> m;
    DFS(0, 0, 0);

    cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
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