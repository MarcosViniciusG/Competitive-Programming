#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vll vector<ll>
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for(ll i = (ll)(a); i >= (ll)(b); --i)

ll cmps = 0;

ll pivot(vll& A, ll l, ll r, ll x) {
    // Each element is compared with the guide x
    vll aux(r - l + 1);
    // cout << x << '\n';
    ll R = r, L = l;
    for (int i = l; i <= R; ++i)
        aux[i - l] = A[i];
    for (int i = l; i <= R; ++i) {
        ll y = aux.at(i - L);
        cmps += 1;
        if (y < x) 
            A[l] = y, l += 1;
        else if (y > x)
            A[r] = y, r -= 1;
    }
    A[l] = x;
    return l;
}

void quicksort(vll& A, ll l, ll r) {
    if (r <= l)
        return;
    // The Master chooses the middle element as a guide
    ll m = (l + r) / 2;
    ll k = pivot(A, l, r, A.at(m));
    // for (ll x : A)
    //     cout << x << ' ';
    // cout << '\n';
    quicksort(A, l, k - 1);
    quicksort(A, k + 1, r);
}

signed main() {
    ll n;
    cin >> n;
    vll xs(n);
    for (ll& x : xs) cin >> x;
    quicksort(xs, 0, n - 1);
    cout << cmps << '\n';
    // for (ll x : xs) cout << x << ' ';
    // cout << '\n';
}