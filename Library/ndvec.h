/*How to use:
    Vec <int, 2> g(n); //graph
    Vec <int, 3> f(n, k, 2) = f[n][k][2]
*/
template <class Tp, int D = 1>
struct Vec : public vector<Vec<Tp, D - 1>> {
    static_assert(D >= 1, "Dimension must be positive");
    template <class... Args>
    Vec(int n = 0, Args... args) : vector<Vec<Tp, D - 1>>(n, Vec<Tp, D - 1>(args...)) {}
};
 
template <class Tp>
struct Vec<Tp, 1> : public vector<Tp> {
    Vec(int n = 0, Tp val = Tp()) : vector<Tp>(n, val) {}
};
