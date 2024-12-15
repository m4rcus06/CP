#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif

const int MX = (int) 5e6 + 1;

int turns[MX];
int lst[4] = {1, 1, 2, 3};
bool isComposite[MX];

void solve() {
	int N; cin >> N;
	vector <int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	int idx = 0;
	for (int i = 0; i < N; ++i) {
		if (turns[a[idx]] > turns[a[i]]) idx = i;
	}

	if (a[idx] % 4 != 0) cout << "Farmer John" << '\n';
	else cout << "Farmer Nhoj" << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif		
	
	turns[0] = 1;
	isComposite[1] = true;
 	for (int i = 2; i < MX; ++i) {
 		if (!isComposite[i]) {
 			for (int j = i; j < MX; j += i) isComposite[j] = true;
 			lst[i % 4] = i;
 		}

 		if (i - lst[i % 4] < 0) cout << i << '\n';
 		if (i % 2 == 0) turns[i] = i / 4 + 1;
 		else turns[i] = turns[i - lst[i % 4]];
 	}

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