#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int inf = 1e9 + 7;

struct Point {
    int x, y;

    Point() {}

    bool operator < (const Point &other) {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }
};

struct Rectangle {
    int Lx, Rx;
    int Ly, Ry;

    Rectangle() {
        Lx = Ly = inf;
        Rx = Ry = -inf;
    }

    int64_t area() {
        return 1LL * (Rx - Lx) * (Ry - Ly);
    }
};

Rectangle Add_point(Rectangle &R, const Point &P) {
    Rectangle res = R;
    res.Lx = min(res.Lx, P.x);
    res.Rx = max(res.Rx, P.x);
    res.Ly = min(res.Ly, P.y);
    res.Ry = max(res.Ry, P.y);

    return res;
}

bool intersect(const Rectangle &L, const Rectangle &R) {
    return (L.Rx > R.Lx && L.Ry > R.Ly);
}

void solve() {
    int N; cin >> N;
    vector<Point> p(N);
    for (int i = 0; i < N; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    Rectangle init;
    for (int i = 0; i < N; ++i) {
        init = Add_point(init, p[i]);
    }
    int64_t init_area = init.area();
    
    auto calc = [&](vector<Point> &p) -> int64_t {
        vector<Rectangle> suffix(N);
        Rectangle rec;
        for (int i = N - 1; i >= 0; --i) {
            rec = Add_point(rec, p[i]);
            suffix[i] = rec;
        }

        Rectangle cur_rec;
        int64_t ans = 0;
        for (int i = 0; i < N; ++i) {
            cur_rec = Add_point(cur_rec, p[i]);
            if (i > 0 && i + 1 < N && p[i].x != p[i + 1].x) {
                ans = max(ans, init_area - cur_rec.area() - suffix[i + 1].area());
            }
        }
        return ans;
    };

    //split X-axis
    sort(p.begin(), p.end());
    int64_t ans = 0;
    ans = max(ans, calc(p));

    //split Y-axis
    for (int i = 0; i < N; ++i) {
        swap(p[i].x, p[i].y);
    }
    sort(p.begin(), p.end());
    ans = max(ans, calc(p));

    cout << ans << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen ("split.in", "r", stdin);
    freopen ("split.out", "w", stdout);
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

