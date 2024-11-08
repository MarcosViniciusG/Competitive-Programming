#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    ll t, n, ai, m;

    string sj;
    cin >> t;
    while(t--) {
        cin >> n;

        ll a[n];
        bool filled[n];

        for(ll i=0; i<n; i++) {
            cin >> ai;
            a[i] = ai;
        }

        cin >> m;
        cin.ignore(1, '\n');
        for(ll i=0; i<m; i++) {
            bool mpbool[26];
            memset(mpbool, false, sizeof(mpbool));
            ll mp[26];
            map<ll, char> mpic;

            bool can = true;
            getline(cin, sj);
            
            if(sj.length()!=n)
                can = false;

            for(ll j=0; can==true && j<n; j++) {
                char c = sj[j];

                if(!mpbool[c-'a']) {
                    if(mpic.find(a[j]) == mpic.end()) {
                        mp[c-'a'] = a[j];
                        mpbool[c-'a'] = true;
                        mpic[a[j]] = c;
                    }
                    else
                        can = false;
                }
                else if(mp[c-'a'] != a[j])
                    can = false;
            }

            if(!can)
                cout << "NO\n";
            else
                cout << "YES\n";
        }

    }

    return 0;
}