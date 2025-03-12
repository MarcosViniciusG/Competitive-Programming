#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector <ll >
#define pll pair <ll , ll >
#define vpll vector <pll >
#define endl '\n'
#define all(xs) xs. begin () , xs.end ()
#define found (x, xs) (xs. find (x) != xs.end ())

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll a, b, C;
    cin >> a >> b >> C;

    string bin = bitset<60>(C).to_string();

    ll mx = __builtin_popcountll(C);
    ll eq = a + b - __builtin_popcountll(C);
    if(eq & 1) {
        cout << -1 << '\n';
        return 0;
    }
    ll x=0, y=0;
    int i=59; 
    ll counter=0;
    for(i=i; i>=0 && counter < mx; i--) {
        if(bin[i]=='1') {
            counter++;
            if(a>=b) {
                x += (1LL << (59 - i));
                a--;
            }
            else {
                y += (1LL << (59 - i));
                b--;
            }
        }
    }

    for(i = 59; i>=0; i--) {
        if(a && b && bin[i]=='0') {
            x += (1LL << (59 - i));
            y += (1LL << (59 - i));
            a--;
            b--;
        }
    }

    if(a || b) {
        cout << -1 << '\n';
        return 0;
    }

    cout << x << ' ' << y << '\n';

    return 0;
}