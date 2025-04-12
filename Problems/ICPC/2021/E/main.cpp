#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

signed main() {
    ll n;
    cin >> n;

    ll T = 0, D = -1;
    queue<ll> fila;
    for (ll i = 0; i < n; ++i) {
        ll t, d;
        cin >> t >> d;
        if (D == -1) {
            T = t + 10;
            D = d;
        }
        else {
            if (d == D) {
                if (t > T) {
                    if (!fila.empty()) {
                        ll ultimo = -1;
                        while (!fila.empty()) {
                            ultimo = fila.front();
                            fila.pop();
                        }
                        T = max(ultimo, T) + 10;
                        D = !D;
                        fila.emplace(t);
                    }
                    else {
                        T = t + 10;
                    }
                }
                else
                    T = t + 10;
            }
            else fila.emplace(t);
        }
        // cout << T << '\n';
    }
    ll ultimo = -1;
    if (!fila.empty()) {
        while (!fila.empty()) {
            ultimo = fila.front();
            fila.pop();
        }
        T = max(ultimo, T) + 10;
    }
    cout << T << '\n';
}