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
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int s, t; cin >> s >> t;
    --s, --t;

    const int L = *max_element(a.begin(), a.end());
    vector <int> isPrime(L + 1, 1), primes;
    vector <vector <int>> factor(L + 1);
    int new_size = n;
    for (int i = 2; i <= L; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            factor[i].push_back(i);
            new_size++;
            for (int j = 2 * i; j <= L; j += i) {
                isPrime[j] = 0;
                factor[j].push_back(i);
            }
        }
    }

    auto get_idx = [&](int p) {
        return lower_bound(primes.begin(), primes.end(), p) - primes.begin() + n;
    };

    vector <vector <int>> g(new_size);
    for (int i = 0; i < n; ++i) {
        for (int j : factor[a[i]]) {
            int k = get_idx(j);
            g[i].push_back(k);
            g[k].push_back(i);
        }
    }

    queue <int> q;
    vector <int> par(new_size, -1);
    par[s] = s;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) break;

        for (int v : g[u]) {
            if (par[v] == -1) {
                par[v] = u;
                q.push(v);
            }
        }
    }

    if (par[t] == -1) {
        cout << -1 << '\n';
        return;
    }

    vector <int> path;
    for (int u = t; u != par[u]; u = par[u]) {
        path.push_back(u + 1);
    }
    path.push_back(s + 1);
    reverse(path.begin(), path.end());

    cout << ((int) path.size() + 1) / 2 << '\n';
    for (int v : path) {
        if (v <= n) cout << v << ' ';
    }
    cout << '\n';
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