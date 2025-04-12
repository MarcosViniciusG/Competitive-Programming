#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    ll n;
    
    queue<ll> left;
    queue<ll> right;

    cin >> n;
    ll T=0;
    ll D=0;
    ll ti, di;
    for(ll i=0; i<n; i++) {
        cin >> ti >> di;
        if(!i) {
            D = di;
            T = ti+10;
        }

        if(di==0)
            left.push(ti);
        else
            right.push(ti);
    }

    while(!left.empty() || !right.empty()) {
        if(!D) {
            while((left.front() <= T || right.empty()) && !left.empty()) {
                T = left.front()+10;
                left.pop();
            }

            if(!right.empty()) {
                T = right.front() + 10;
                D = 1;
                right.pop();
            }
        }
        else {
            while((right.front() <= T || left.empty()) && !right.empty()) {
                T = right.front()+10;
                right.pop();
            }

            if(!left.empty()) {
                T = left.front() + 10;
                D = 0;
                left.pop();
            }
        }
    }

    cout << T << '\n';

    return 0;
}