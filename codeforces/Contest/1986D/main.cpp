#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int INF = 1e9 + 7;

void solve() {
    int N; cin >> N;
    string S; cin >> S;

    int ans = INF;
    for (int i = 0; i + 1 < N; ++i) {
        vector <int> nums;
        for (int j = 0; j < N; ++j) {
            if (j == i) { 
                nums.push_back(10 * (S[j] - '0') + (S[j + 1] - '0'));
                j += 1;
            }
            else nums.push_back(S[j] - '0');
        }
        
        int res = 0;
        bool all_1 = true;
        for (int j = 0; j < (int) nums.size(); ++j) {
            if (nums[j] != 1) all_1 = false;
            if (nums[j] == 0) {
                res = 0;
                break;
            }
            if (nums[j] == 1) continue;
            res += nums[j];
        }
        if (all_1) res = 1;
        ans = min(ans, res);
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