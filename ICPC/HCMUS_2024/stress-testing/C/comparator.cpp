#include <bits/stdc++.h>
using namespace std;

const string NAME = "C";

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int64_t Rand(long long l, long long h) {
    assert(l <= h);
    return uniform_int_distribution<long long>(l, h)(rd);
}

bool check() {
    system((NAME + "_brute" + ".exe").c_str());
    system((NAME + "_optimized" + ".exe").c_str());

    return system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) == 0;
}

bool g(string &A, string &B) {
    if (A.size() > B.size()) return true;
    if (A.size() < B.size()) return false;
    return A > B;
}

void stricty_large(long long low_bound, long long up_bound, int l_idx, int r_idx) {
    for (int iTest = l_idx; iTest <= r_idx; iTest++) {
        ofstream inp((NAME + ".in").c_str());
        long long L = Rand(low_bound, up_bound);
        long long R = Rand(L, min(up_bound, L + Rand(1, 1e6)));

        inp << L << ' ' << R;
        inp.close();

        if (check()) {
            cout << "ACCEPTED\n";
        } else {
            cout << "Difference found!\n";
            cout << "Testcase: " << L << ' ' << R << '\n';
            return;
        }
    }
}

void random_numbers(long long low_bound, long long up_bound, int l_idx, int r_idx) {
    for (int iTest = l_idx; iTest <= r_idx; iTest++) {
        ofstream inp((NAME + ".in").c_str());
        long long L = Rand(low_bound, up_bound);
        long long R = Rand(L, min(up_bound, L + Rand(1, 1e6)));
        if (L > R) swap(L, R);

        inp << L << ' ' << R;
        inp.close();

        if (check()) {
            cout << "ACCEPTED\n";
        } else {
            cout << "Difference found!\n";
            cout << "Testcase: " << L << ' ' << R << '\n';
            return;
        }
    }
}

int main() {
    srand(time(NULL));
    random_numbers(1, 1e18, 1, 500);
    stricty_large(1e17, 1e18, 1, 500);

    return 0;
}