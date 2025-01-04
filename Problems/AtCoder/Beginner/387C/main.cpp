#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll L, R;
    cin >> L >> R;

    ll result=0;
    for(ll i=1; i<=9; i++) {
        for(ll j=10; (j*i)<=R; j*=10) {
            if((j*i) < L)
                continue;

            ll pos=1;
            ll place=j/10;
            while(place > 0) {
                pos *= i;
                place /= 10;
            }
            result += pos;
        }
    }

    string Rs = to_string(R);
    ll most_sig = Rs[0] - '0';
    ll prod=1;
    for(int i=1; i<int(Rs.length()); i++)
    {
        ll new_most_sig = Rs[i] - '0';
        cout << new_most_sig << '\n';

        if(new_most_sig >= most_sig)
            break;
        else {
            ll pro=new_most_sig-most_sig;
            for(int j=i+1, pow10=1; j<int(Rs.length()); j++, pow10*=10) {
                pro *= most_sig-1;
            }
            prod += pro;
        }
    }
    

    cout << result - prod << '\n';
    return 0;
}