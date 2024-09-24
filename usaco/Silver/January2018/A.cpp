#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int N; cin >> N;
    vector<int> l(N), r(N);
    for (int i = 0; i < N; ++i) {
        cin >> l[i] >> r[i];

        //avoid l[i] = 0 or r[i] = 0;
        ++l[i], ++r[i];
    }

    vector<int> nums;
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < 2; ++k) {
            nums.push_back(l[i] - k);
            nums.push_back(r[i] - k);
        }
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    auto get_idx = [&](int x) -> int {
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
    };

    int sz = nums.size();
    vector<int> cnt(sz + 1, 0);
    for (int i = 0; i < N; ++i) {
        int L = get_idx(l[i]);
        int R = get_idx(r[i]);

        cnt[L]++;
        cnt[R]--;
    }

    for (int i = 1; i <= sz; ++i) {
        cnt[i] += cnt[i - 1];
    }

    int total = 0;
    for (int i = 1; i <= sz; ++i) {
        total += (cnt[i] > 0) * (nums[i] - nums[i - 1]);
    }

    vector<int> change(sz + 1, 0);
    for (int i = 1; i <= sz; ++i) {
        change[i] = change[i - 1] + (cnt[i] == 1) * (nums[i] - nums[i - 1]);
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int rem = change[get_idx(r[i] - 1)] - change[get_idx(l[i] - 1)];
        ans = max(ans, total - rem);
    }

    cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen ("lifeguards.in", "r", stdin);
    freopen ("lifeguards.out", "w", stdout);
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

