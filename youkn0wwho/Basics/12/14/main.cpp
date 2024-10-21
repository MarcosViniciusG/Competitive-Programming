#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    ll S, T;
    cin >> S >> T;

    ll cS = 0;
    for(ll a=0; a<=S; a++)
    for(ll b=0; b<=(S-a); b++) 
    for(ll c=0; c<=(S-a-b); c++) {
        if(a*b*c <= T)
            cS++;
    }

    cout << cS << endl;
    return 0;
}