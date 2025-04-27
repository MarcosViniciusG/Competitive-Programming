#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll b, l;

ll binexp(ll a, ll x) {
    if(x==0)
        return 1;
    else if(x==1)
        return a;

    if(x % 2 == 0) {
        ll result = binexp(a,x/2);
        return (result*result) % (b+1);
    }
    
    ll result = binexp(a, (x-1)/2);
    return (result*result*a) % (b+1);
}

signed main()
{
    cin >> b >> l;
    
    vector<ll> d(l);
    for(ll &i: d)
        cin >> i;

    ll nov=0;
    for(int i = 0; i < l; i++)
    {
        ll pot = binexp(b, l-i-1);
        ll res = (pot*d[i]) % (b+1);
        nov += res;
        nov %= (b+1);        
    }

    if(nov % (b+1)==0) {
        cout << "0 0" << '\n';
        return 0;
    }

    ll ansi=-1;
    ll ans=-1;
    for(int i = 0; i < l; i++)
    {
        ll pot = binexp(b, l-i-1);
        ll res = (pot*d[i]) % (b+1);
        if((nov-res) % (b+1) == 0) {
            ansi = i+1;
            ans = 0;
            break;
        }
        if((d[i]-1)>=0 && (nov-pot) % (b+1) == 0) {
            ansi = i+1;
            ans = d[i]-1;
            break;
        }
    }


    cout << ansi << ' ' << ans << '\n';
}

// 2 3 4 5 6 9 mod 11 = 4
// 2 3 0 5 6 9 mod 11 = 0