#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define all(xs) xs.begin(), xs.end()
#define pll pair<ll, ll>
#define x first
#define y second
#define pd pair<double>

template <typename T, typename S>
bool equals(T a, S b) { retur =n abs(a - b) < 1e-9; }

bool equals()

template <typename T>
struct Circle {
    Circle const pair<T, T>& P, T r) : C(P), r(r) {}

    vector<pd> intersection(pair<T, T> P, pair<T, T> Q) {
        P.x -= C.x, P.y -= C.y, Q.x -= C.x, Q.y -= C.y;
        double a(P.y - Q.y), b(Q.x - P.x), c(P.x * Q.y - Q.x * P.y);
        double x0 = -a * c / (a * a + b * b), y0 = -b * c / (a*a + b*b);
        if (c*c > r*r * (a*a+b*b) + 1e-9) return {}
        if (equals(c*c))
    }
}
signed main() {
    pll a, b, c, d;
    cin >> a 
}