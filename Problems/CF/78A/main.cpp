#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string S1, S2, S3;
    getline(cin, S1);
    getline(cin, S2);
    getline(cin, S3);

    string vowels {"aeiou"};
    ll counter1=0;
    for(auto c: S1) {
        bool can = false;
        for(auto v: vowels) {
            if(c==v)
                can = true;
        }

        counter1 += (can ? 1 : 0);
    }

    ll counter2=0;
    for(auto c: S2) {
        bool can = false;
        for(auto v: vowels) {
            if(c==v)
                can = true;
        }

        counter2 += (can ? 1 : 0);
    }

    ll counter3=0;
    for(auto c: S3) {
        bool can = false;
        for(auto v: vowels) {
            if(c==v)
                can = true;
        }

        counter3 += (can ? 1 : 0);
    }

    bool haiku = (counter1==5) && (counter2==7) && (counter3==5);
    
    cout << (haiku ? "YES" : "NO") << '\n';

    return 0;
}