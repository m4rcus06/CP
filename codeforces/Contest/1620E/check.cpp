#include <bits/stdc++.h>
using namespace std;

const string NAME = "DUONGHOA";

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int64_t Rand(long long l, long long h) {
    assert(l <= h);
    return uniform_int_distribution<long long>(l, h)(rd);
}

int solve(const int &N, const int &M, const vector <int> &A) {
    int mx = *max_element(A.begin(), A.end());
    vector <int> cnt(mx + 1, 0);

    int ans = N;
    int f = 0;
    for (int l = 0, r = 0; r < N; ++r) {
        if (cnt[A[r]] == 0) ++f;
        cnt[A[r]]++;
 
        while (f == M) {
            ans = min(ans, r - l + 1);
            cnt[A[l]]--;
            if (cnt[A[l]] == 0) --f;
            l++;
        }
    }
    return ans;
}

void gen(int up_bound, int l_idx, int r_idx) {
    for (int iTest = l_idx; iTest <= r_idx; iTest++) {
        ofstream inp(("test.in"));
        int q = Rand(2, up_bound);
        vector<array <int, 3>> ops;
        ops.push_back({1, 1, 0});
        for (int i = 1; i < q; ++i) {
        	int t = Rand(1, 2);
        	if (t == 1) ops.push_back({t, Rand(1, 10), 0});
        	else ops.push_back({t, Rand(1, 10), Rand(1, 10)});
        }

        inp << q << '\n';
        for (int i = 0; i < q; ++i) {
        	if (ops[i][0] == 1) inp << ops[i][0] << ' ' << ops[i][1] << '\n';
        	else inp << ops[i][0] << ' ' << ops[i][1] << ' ' << ops[i][2] << '\n';
        }
        inp.close();

        system("main.exe");
        system("brute.exe");
        if ((system(("fc test.ans test.out")))) {
            cout << "WRONG ANS";
            return;
        }
  		else cout << "OK";
  		cout << '\n';
    }
}

int main() {
    srand(time(NULL));

    gen(20, 1, 1000);
    return 0;
}