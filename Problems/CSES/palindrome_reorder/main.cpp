#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<char, ll> histogram(string s) {
    map<char, ll> hist;
    for(auto c: s)
        hist[c]++;

    return hist;
}

int main()
{
    string s;
    cin >> s;

    map<char, ll> hist = histogram(s);
    string ans="";

    ll counter=0;
    char odd='$';
    ll nodd=-1;
    for(auto par: hist) {
        char c = par.first;
        ll n = par.second;
        counter += (ll)(n & 1);

        if(n & 1) {
            odd = c;
            nodd = n;
        }

        for(ll i=0; i<n/2 && !(n & 1); i++) {
            ans+=c;
        }
    }

    if(counter>1) 
        cout << "NO SOLUTION\n";
    else {
        cout << ans;
        if(nodd!=-1) {
            for(ll i=0; i<nodd; i++)
                cout << odd;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }

    return 0;
}