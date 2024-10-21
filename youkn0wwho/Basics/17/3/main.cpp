#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> divs;
    divs.push_back(1);
    for(ll i=2; i*i<=n; i++) {
        if(n % i==0) {
            if(n/i == i)
                divs.push_back(i);
            else {
                divs.push_back(i);
                divs.push_back(n/i);
            }
        }
    }

    if(divs[divs.size()-1]!=n)
        divs.push_back(n);

    sort(divs.begin(), divs.end());

    if(k <= divs.size())
        cout << divs[k-1] << endl;
    else
        cout << -1 << endl;

    return 0;
}