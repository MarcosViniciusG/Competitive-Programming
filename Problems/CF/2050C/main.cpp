#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    string n;

    cin >> t;
    cin.ignore(1, '\n');
    while(t--) {
        getline(cin, n);

        ll sum = 0;
        ll c2=0;
        ll c3=0;

        for(auto c: n) {
            ll d = (c-'0');
            sum += d;
            if(d==2)
                c2++;
            else if(d==3)
                c3++;
        }

        ll n2_needed=0;
        ll fake_sum = sum;
        while(fake_sum % 9) {
            fake_sum+=2;
            n2_needed++;
        }

        while(n2_needed >= 3 && c3 > 0) {
            c3--;
            n2_needed -= 3;
        }

        while(n2_needed && c2 > 0) {
            c2--;
            n2_needed -= 1;
        }

        if(n2_needed)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}