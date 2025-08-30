#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vll vector<ll>
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for(ll i = (ll)(a); i >= (ll)(b); --i)
#define eb emplace_back()

signed main() {
    ll n;
    cin >> n;
    n*=2;
    vll xs(n);
    for (ll& x : xs) cin >> x;

    map<ll, ll> hist, oldhist;
    ll total = 0;
    ll val = 0, saveval = 0;
    for(int i = 0; i < n; i++)
    {
        if(oldhist.count(xs[i]))
        {
            if(i - oldhist[xs[i]] < saveval)
            {
                val -= saveval;
                saveval = i - oldhist[xs[i]];
                val += saveval;
            }
        }

        if(hist.count(xs[i]))
        {
            total++;
            val += i - hist[xs[i]];
            saveval = i - hist[xs[i]];

            oldhist.clear();
            oldhist = hist;

            hist.clear();
        }

        hist[xs[i]] = i;
    }

    cout << total << " " << val << '\n';
}