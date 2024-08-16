#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {


    ll t;
    string a;

    cin >> t;
    cin.ignore(1, '\n');

    for(ll i=0; i<t; i++) {
        bool can = false;

        getline(cin, a);
        if(a.length() == 3 && a[0]=='1' && a[1]=='0' && (a[2] - '0')>=2)
            can = true;
        else if(a.length() > 3 && a[0]=='1' && a[1]=='0' && (a[2] - '0')>=1)
            can = true;

        if(can)
            cout << "Yes\n";
        else 
            cout << "No\n";
    }



    return 0;
}