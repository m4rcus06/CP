#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include </home/marcus06/vimcp/Library/debug.h>
#else
#define debug(...) 
#endif
 
void solve() {
    int N, M; cin >> N >> M;
    vector <array <int,2>> Jiro(N);
    for (int i = 0; i < N; ++i) {
        string type;
        int stat;
        cin >> type >> stat;

        if (type == "ATK") Jiro[i] = {1, stat};
        else Jiro[i] = {0, stat};
    }

    vector <int> Ciel(M);
    for (int i = 0; i < M; ++i) {
        cin >> Ciel[i];
    }

    sort(Ciel.begin(), Ciel.end(), [&](int i, int j) {return i > j;});

    sort(Jiro.begin(), Jiro.end(), [&](array <int,2> i, array <int,2> j) {
        if (i[0] == j[0]) return i[1] < j[1];
        return i[0] > j[0];
    });

    int first_choice = 0;
    for (int i = 0, j = 0; i < M; ++i) {
        if (j >= N || Jiro[j][0] == 0) break;
        if (Jiro[j][1] <= Ciel[i]) {
            first_choice += Ciel[i] - Jiro[j][1];
            j++;
        }
    }

    sort(Jiro.begin(), Jiro.end(), [&](array <int, 2> i, array <int, 2> j) {
        if (i[0] == j[0]) return i[1] > j[1];
        return i[0] < j[0];
    });
    sort(Ciel.begin(), Ciel.end());

    vector <bool> used(M, false);
    int second_choice = 0;
    for (int i = 0; i < N; ++i) {
        bool found = false;
        for (int j = 0; j < M; ++j) {
            if (used[j]) continue;

            if (Jiro[i][0] == 0) {
                if (Ciel[j] > Jiro[i][1]) {
                    used[j] = true;
                    found = true;
                    break;
                }
            }

            if (Jiro[i][0] == 1) {
                if (Ciel[j] >= Jiro[i][1]) {
                    used[j] = true;
                    found = true;
                    second_choice += Ciel[j] - Jiro[i][1];
                    break;
                }
            }
        }
        if (found == false) {
            cout << first_choice << '\n';
            return;
        }
    }

    for (int i = 0; i < M; ++i) {
        if (used[i] == false) second_choice += Ciel[i];
    }
    cout << max(first_choice, second_choice) << '\n';
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

