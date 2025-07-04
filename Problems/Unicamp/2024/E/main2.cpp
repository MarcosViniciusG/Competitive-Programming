#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>

// 6*2 + 10*(-1)  = 2
// 1*15 + 2*(-7) = 1
// 6 * (-14) + 10*7 = 1

ll gcd_(ll a, ll b) {
    // cout << "A: " << a << '\n';
    // cout << "B: " << b << '\n';
    if (a == b) return 0;
    if (b == 0) return 0;
    return a / b + gcd_(b, a % b);
}

tuple<ll, ll, ll> diophantine(ll a, ll b, ll c= 1) {
    if (b == 0) {
        if (c % a !=  0) return {LLONG_MAX, LLONG_MAX, a};
        return {c / a, 0, a};
    }
    auto [x, y, d] = diophantine(b, a % b, c);
    if (x == LLONG_MAX) return {x, y, a};
    return {y, x - a/b * y, d};
} 

pair<bool, vll> solve(vll v, ll n, ll k) {
    // cout << n << ": ";
    // for(auto e: v)
    //     cout << e << ' ';
    // cout << '\n';

    if(n==1) {
        vll ans;
        ans.push_back(1);
        if(v[0] > k || k % v[0] != 0)
            return {false, ans};
        else {
            ans.pop_back();
            ans.push_back(k / v[0]);
            return {true, ans};
        }
    }

    vll xs;
    ll i=0;

    vll coef;
    for(;(i+1)<n; i+=2) {
        ll g = gcd(v[i], v[i+1]);
        xs.push_back(g);
        auto [x, y, d] = diophantine(v[i], v[i+1], g);
        coef.push_back(x);
        coef.push_back(y);
    }

    if(n & 1) {
        xs.push_back(v[n-1]);
        coef.push_back(1);
    }

    // cout << n << ": ";
    // for(auto e: coef)
    //     cout << e << ' ';
    // cout << '\n';
    
    ll m = xs.size();
    auto [ver, new_coef] = solve(xs, m, k);

    ll j=0;
    for(ll i=0; i<m; i++) {
        if(j+1 < n) {
            coef[j] *= new_coef[i];
            coef[j+1] *= new_coef[i];
        }
        else if(j < n)
            coef[j] *= new_coef[i];
        j+=2;
    }

    return {ver, coef};
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vll xs;
        ll x;
        for (ll i=0; i<n; i++) {
            cin >> x;
            xs.push_back(x);
        }
        // auto [ver, new_coef] = solve(xs, n, k);
        // if(ver) {
        //     cout << "YES\n";
        //     for(ll i=0; i<n; i++) {
        //         cout << new_coef[i];
        //         if(i!=n-1) cout << ' ';
        //     }
        //     cout << '\n';
        // }
        // else
        //     cout << "NO\n";

        vll ans(n ,0);
        for(ll i=0; i<n; i++) {
            for(ll j=i; j<n; j++) {
                auto [x, y, d] = diophantine(xs[i], xs[j], k);
                if(x!= LLONG_MAX) {
                    ans[i] = x;
                    ans[j] = y;
                }
            }
        }
        
        for(auto e: ans)
            cout << e << ' ';
        cout << '\n';
        
    }
}