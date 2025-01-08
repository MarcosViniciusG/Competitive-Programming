#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

ll counting(ll x) {
    string place="";
    string xs = to_string(x);
    place += xs[0];
    for(ll i=0; i<ll(xs.length())-1; i++) {
        place += '0';
    }

    ll smallest_n = stoll(place);
    
    ll result=0;
    for(ll i=1; i<=9; i++) {
        for(ll j=10; (j*i)<smallest_n; j*=10) {
            ll pos=1;
            ll place=j/10;
            while(place > 0) {
                pos *= i;
                place /= 10;
            }
            result += pos;
        }
    }

    place="";
    place += xs[0];
    bool activate=false;
    for(ll i=1; i<ll(xs.length()); i++) {
        if(xs[i] < xs[0] && !activate)
            place += xs[i];
        else {
            activate = true;
            place += xs[0]-1;
        }
    }

    ll prod=1;
    cout << place << '\n';
    for(ll i=1; i<ll(place.length()); i++) {
        prod *= (place[i]-'0')+1;
    }
    cout << prod << ' ' << result << '\n';

    return result + prod;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll L, R;
    cin >> L >> R;

    ll resultR = counting(R);
    ll resultL = counting(L);
    

    cout << resultR - resultL + 1 << '\n';
    return 0;
}