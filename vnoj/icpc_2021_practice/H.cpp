#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif

const int mod = 1e9 + 7;
const int base = 257;

int get_hash(vector<int> &a) {
    int res = 0;
    int cur_pw = 1;
    for (int i = 0; i < (int) a.size(); ++i) {
        res = ((1LL * res * cur_pw % mod) + a[i]) % mod;
        cur_pw = 1LL * cur_pw * base % mod;
    }
    return res;
}
 
void solve() {
    int n, m, d; cin >> n >> m >> d;
    vector<vector<int>> train_data(n, vector<int>(d));
    vector<int> train_index(n);
    for (int i = 0; i < n; ++i) {
        cin >> train_index[i];
        for (int j = 0; j < d; ++j) {
            cin >> train_data[i][j];
        }
    }

    vector<vector<int>> sample(m, vector<int>(d));
    vector<int> sample_index(m);
    for (int i = 0; i < m; ++i) {
        cin >> sample_index[i];
        for (int j = 0; j < d; ++j) {
            cin >> sample[i][j];
        }
    }

    vector<vector<int>> hash_code(26);
    for (int i = 0; i < n; ++i) {
        int idx = train_index[i];
        hash_code[idx].push_back(get_hash(train_data[i]));
    }

    for (int i = 0; i < 26; ++i) {
        sort(hash_code[i].begin(), hash_code[i].end());
    }

    for (int i = 0; i < m; ++i) {
        int idx = sample_index[i];
        int code = get_hash(sample[i]);

        if (binary_search(hash_code[idx].begin(), hash_code[idx].end(), code)) {
            cout << "BAD" << '\n';
        } else {
            cout << "GOOD" << '\n';
        }
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

