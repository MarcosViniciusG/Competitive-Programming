#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vll vector<ll>
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for(ll i = (ll)(a); i >= (ll)(b); --i)
#define all(xs) xs.begin(), xs.end()

/**
 *  @return  Vectors with primes from [1, n] and smallest prime factors.
 *  Time complexity: O(Nlog(log(N)))
*/
pair<vll, vll> sieve(ll n) {
    vll ps, spf(n + 1);
    rep(i, 2, n + 1) if (!spf[i]) {
        ps.emplace_back(i);
        for (ll j = i; j <= n; j += i)
            if (!spf[j]) spf[j] = i;
    }
    return { ps, spf };
}

/**
 *  @return  Unordered vector with all divisors of x.
 *  Time complexity: O(sqrt(N))
*/
vll divisors(ll x) {
    vll ds;
    for (ll i = 1; i * i <= x; ++i)
        if (x % i == 0) {
            ds.emplace_back(i);
            if (i * i != x) ds.emplace_back(x / i);
        }
    return ds;
}

signed main() {
    ll n;
    cin >> n;

    vll xs(n);
    for(auto& x : xs)cin >> x;

    vll diffs;
    ll diff = xs[0];
    for(int i = 1; i < n; i++)
    {
        diffs.emplace_back(xs[i] - diff);
    }

    ll mdc = diffs[0];
    for(int i = 1; i < diffs.size(); i++)
    {
        mdc = gcd(diffs[i], mdc);
    }

    if(mdc > 1)
    {
        vll divs = divisors(mdc);
        cout << 1 << " " << divs.size() -1 << '\n';
    }

    else
    {
        ll small = *max_element(all(xs));
        auto [ys, zs] = sieve(small);
        
        vll factors;
        for(auto y : ys)
        {
            set<ll> am;
            bool add = true;
            for(auto x : xs) am.insert(x%y);

            if(am.size() == 2) factors.emplace_back(y);
        }

        vll newfactors;
        for(int i = 0; i < factors.size(); i++)
        {
            for(int j = 0; j < factors.size(); j++)
            {
                newfactors.emplace_back(factors[i] * factors[j]);
            }
        }

        for(auto nf : newfactors)
        {
            set<ll> am;
            bool add = true;
            for(auto x : xs) am.insert(x%nf);

            if(am.size() == 2) factors.emplace_back(nf);
        }

        set<ll> ans;
        for(auto f : factors) ans.insert(f);

        cout << 2 << " " << ans.size() << '\n';
    }

    return 0;
}