#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

//replace with your directory
#ifdef LOCAL
#include <C:/Coding/CP/templates/content/debug/debug.h>
#else
#define debug(...) 
#endif

const int mxN = 1000;
const int mxM = 500;

int N, M, K;
pair <int, int> nxt[mxN][mxM];
bool visited[mxN][mxM];
int edge[mxN][2];
int moves[mxM];

void DFS(int i, int j) {
	nxt[i][j].first = edge[i][moves[j]];
	nxt[i][j].second = (j + 1) % M;
	if (visited[i][j]) return;
	visited[i][j] = true;

	DFS(edge[i][moves[j]], (j + 1) % M);
}

void solve() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		cin >> edge[i][0] >> edge[i][1];
		--edge[i][0], --edge[i][1];
	}

	for (int i = 0; i < M; ++i) {
		char c; cin >> c;
		if (c == 'L') moves[i] = 0;
		else moves[i] = 1;
	}

	memset(nxt, -1, sizeof nxt);
	DFS(0, 0);

	lli numEdge = 1LL * K * M;

	//do Floyd Tortoise and Hare
	pair <int, int> x = {0, 0}, y = {0, 0};
	do {
		x = nxt[x.first][x.second];
		y = nxt[y.first][y.second];
		y = nxt[y.first][y.second];
	} while (x != y);

	x = {0, 0};
	while (x != y && numEdge > 0) {
		--numEdge;
		x = nxt[x.first][x.second];
		y = nxt[y.first][y.second];
	}

	//now x is in Cycle;
	//calculate the cycle Length
	int cycleLength = 0;
	do {
		x = nxt[x.first][x.second];
		++cycleLength;
	} while (x != y);

	numEdge %= cycleLength;
	while (numEdge--) {
		x = nxt[x.first][x.second];
	}

	cout << x.first + 1 << '\n';
}
 
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#else
    freopen("cruise.in", "r", stdin);
    freopen("cruise.out", "w", stdout);
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