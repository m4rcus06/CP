#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif

vector <int> moves(const vector <int> who) {
	cout << "next ";
	for (int i = 0; i < (int) who.size(); ++i) {
		cout << who[i] << ' ';
	}
	cout << endl;

	int N; cin >> N;
	vector <int> g(10);
	for (int i = 0; i < N; ++i) {
		string S; cin >> S;
		for (auto &c: S) {
			g[c - '0'] = i;
		}
	}

	return g;
}
 
void solve() {
	moves({0});
	vector <int> group_index = moves({0, 1});
	while (group_index[0] != group_index[1]) {
		group_index = moves({0});
		group_index = moves({0, 1});
	}

	while (group_index[2] != group_index[0]) {
		group_index = moves({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
	}

	cout << "done" << endl;
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