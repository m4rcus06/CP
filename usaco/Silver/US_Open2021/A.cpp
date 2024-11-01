#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif

namespace std {
 
template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
    static_assert(D >= 1, "Dimension must be positive");
    template <typename... Args>
    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
 
template <typename T>
struct Vec<1, T> : public vector<T> {
    Vec(int n = 0, T val = T()) : std::vector<T>(n, val) {}
};
}

const int N = 25;	

int n;
Vec <2, char> a(N, N);
pair <int, int> ops[N][N];
int pow_3[10];
bool cache[N][N][19683]; //19683 is 3^9

int convert(char c) {
	if (c == '.') return 0;
	if (c == 'M') return 1;
	return 2;
}

bool can_win(int mask) {
	Vec <2, int> board(3, 3);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			board[i][j] = mask % 3;
			mask /= 3;
		}
	}

	for (int i = 0; i < 3; ++i) {
		if (board[i][0] == 1 && board[i][1] == 2 && board[i][2] == 2) return true;
		if (board[i][0] == 2 && board[i][1] == 2 && board[i][2] == 1) return true;

		if (board[0][i] == 1 && board[1][i] == 2 && board[2][i] == 2) return true;
		if (board[0][i] == 2 && board[1][i] == 2 && board[2][i] == 1) return true;
	}

	if (board[0][0] == 1 && board[1][1] == 2 && board[2][2] == 2) return true;
	if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 1) return true;
	if (board[0][2] == 1 && board[1][1] == 2 && board[2][0] == 2) return true;
	if (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 1) return true;
	return false;
}

vector <int> ans;
void DFS (int i, int j, int mask) {
	if (i < 0 || i >= n || j < 0 || j >= n || a[i][j] == '#') return;

	if (cache[i][j][mask] == true) return;	
	cache[i][j][mask] = true;

	if (a[i][j] == 'O' || a[i][j] == 'M') {
		int x = ops[i][j].first, y = ops[i][j].second;
		int idx = 3 * x + y;	

		int char_at = (mask / pow_3[idx]) % 3;
		if (char_at == 0) {
			mask += (convert(a[i][j]) * pow_3[idx]);
			if (can_win(mask)) {
				ans.push_back(mask);
				return;
			}
		}
	}

	DFS (i - 1, j, mask);
	DFS (i, j - 1, mask);
	DFS (i + 1, j, mask);
	DFS (i, j + 1, mask);
}
 
void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3 * n; j += 3) {
			char c[3];
			cin >> c[0] >> c[1] >> c[2];

			a[i][j / 3] = c[0];
			if (c[0] == 'O' || c[0] == 'M') {
				ops[i][j / 3] = {c[1] - '1', c[2] - '1'};
			}
		}
	}

	pow_3[0] = 1;
	for (int i = 1; i < 10; ++i) {
		pow_3[i] = pow_3[i - 1] * 3;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] == 'B') {
				DFS(i, j, 0);
			}
		}
	}
	sort (ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

	cout << (int) ans.size() << '\n';
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