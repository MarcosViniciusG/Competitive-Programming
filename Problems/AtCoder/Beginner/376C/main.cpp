#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, ai, bi;
    cin >> n;

    vector<ll> a, b;

    for(ll i=0; i<n; i++) {
        cin >> ai;
        a.push_back(ai);
    }

    for(ll i=0; i<n-1; i++) {
        cin >> bi;
        b.push_back(bi);
    }

    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());

    ll j=0;
    ll choosen = 0;
    ll skip=0;

    for(ll i=0; i<n-1 && (j<n); i++) {
        if(b[i] < a[j]) {
            if(choosen) {
                choosen=-1;
                break;
            } 

            choosen = a[j];
            bool found = false;
            while (j<n)
            {
                skip++;
                if(b[i] >= a[j]) {
                    found = true;
                    break;
                }
                j++;
            }

            if(!found) {
                choosen = -1;
                break;
            }
        }
        j++;
    }

    if((!choosen))
        choosen = a[n-1];

    cout << choosen << endl;

    return 0;
}