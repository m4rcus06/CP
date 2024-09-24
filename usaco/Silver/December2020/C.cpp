#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

struct Cow {
    char dir;
    int x, y, idx;

    bool operator < (const Cow &other) {
        if (dir == 'E') return y < other.y;
        return x < other.x;
    }
};

void solve() {
    int N; cin >> N;
    vector<Cow> East, North;
    for (int i = 0; i < N; ++i) {
        char dir;
        int x, y;
        cin >> dir >> x >> y;

        (dir == 'E' ? East : North).push_back({dir, x, y, i});
    }
    sort(East.begin(), East.end());
    sort(North.begin(), North.end());
    
    vector<int> ans(N, 0);
    vector<int> blocked(N, 0);
    for (int i = 0; i < (int) East.size(); ++i) {
        for (int j = 0; j < (int) North.size(); ++j) {
            if (East[i].x <= North[j].x && North[j].y <= East[i].y && !blocked[East[i].idx] && !blocked[North[j].idx]) {
                int dist_x = North[j].x - East[i].x;
                int dist_y = East[i].y - North[j].y;

                if (dist_x < dist_y) {
                    ans[East[i].idx] += ans[North[j].idx] + 1;
                    blocked[North[j].idx] = 1;
                } else if(dist_y < dist_x) {
                    ans[North[j].idx] += ans[East[i].idx] + 1;
                    blocked[East[i].idx] = 1;
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << '\n';
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

