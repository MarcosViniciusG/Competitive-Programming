#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    ll N, Li, Ri, minLi, minLiI, maxRi, maxRiI;
    cin >> N;

    vector<ll> L;
    vector<ll> R;

    ll sumL = 0;
    ll sumR = 0;
    for(ll i=0; i<N; i++) {
        cin >> Li >> Ri;
        L.push_back(Li);
        R.push_back(Ri);

        sumL += Li;
        sumR += Ri;
    }

    if((sumL > 0) || (sumR < 0))
        cout << "No\n";
    
    vll X = L;

    ll sumX = sumL;

    for(ll i=0; i<N; i++) {
        ll d = min(R[i] - L[i], -sumX);
        sumX += d;
        X[i] += d;
    }

    cout << "Yes\n";
    for(auto e: X) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}