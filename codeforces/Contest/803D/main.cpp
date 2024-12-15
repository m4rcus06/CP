#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int K; cin >> K;
    vector <string> A;
    string S;
    while (cin >> S) {
        A.emplace_back(S);
    }

    vector <int> len;
    for (int i = 0; i < (int) A.size(); ++i) {
        int cnt = 0;
        for (int j = 0; j < (int) A[i].size(); ++j) {
            ++cnt;
            if (A[i][j] == '-') {
                len.push_back(cnt);
                cnt = 0;
            }
        }
        len.push_back((cnt == 0 || i + 1 == (int) A.size()) ? cnt : cnt + 1);
    }

    auto isGood = [&](int x) -> bool {
        int lines = 0;
        int total_length = 0;
        for (int i = 0; i < (int) len.size(); ++i) {
            if (len[i] > x) return false;
            if (total_length + len[i] > x) {
                ++lines;
                total_length = 0;
            }
            total_length += len[i];
        }
        lines += total_length > 0;

        return lines <= K;
    };


    int l = 0, r = accumulate(len.begin(), len.end(), 0);
    while (r - l > 1) {
        int m = (l + r) / 2;

        if (isGood(m)) r = m;
        else l = m;
    }

    cout << r << '\n';
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