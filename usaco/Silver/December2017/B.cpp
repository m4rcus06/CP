#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int N, G; cin >> N >> G;
    vector<int> days(N), CowId(N), delta(N);
    int max_days = 0;
    for (int i = 0; i < N; ++i) {
        char sign;
        int day, id, v;
        cin >> day >> id >> sign >> v;

        max_days = max(max_days, day);
        if (sign == '-') v *= -1;
        --day, --id;

        days[i] = day;
        CowId[i] = id;
        delta[i] = v;
    }

    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {return days[i] < days[j]; });

    map<int, int> CowInfo;
    for (int i = 0; i < N; ++i) {
        CowInfo[CowId[i]] = G;
    }

    multiset<int> mset;
    for (int i = 0; i < (int) CowInfo.size(); ++i) {
        mset.insert(G);
    }
    //make a clone (because FJ have large number of cows, most of them remain exactly at G gallons of milk so we only need to make one clone);
    mset.insert(G);

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int f = 0;
        int idx = ord[i];

        int &v = CowInfo[CowId[idx]];
        int current_max = *mset.rbegin();

        mset.erase(mset.find(v));
        if (v == current_max) {
            int new_max = (mset.empty() ? -1 : *mset.rbegin());
            if (v == new_max) ++ans;
            else {
                if (v + delta[idx] <= new_max) ++ans;
            }
        } else {
            if (v + delta[idx] >= current_max) ++ans;
        }

        v += delta[idx];
        mset.insert(v);

        ans += f;
    }

    cout << ans << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
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

