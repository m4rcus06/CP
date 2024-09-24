#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    string S; cin >> S;
    int K; cin >> K;

    vector<int> cnt(26, 0);
    auto check = [&]() {
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > K) return false; 
        }
        return true;
    };

    int64_t ans = 0;
    for (int i = 0, j = 0; i < (int) S.size(); ++i) {
        cnt[S[i] - 'a']++;
        while (!check()) {
            cnt[S[j] - 'a']--;
            j++;
        }
        ans += i - j + 1;
    }

    cout << ans << '\n';
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

