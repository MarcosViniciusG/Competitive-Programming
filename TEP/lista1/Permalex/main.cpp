#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define endl '\n'

vector<char> ranking;

ll n_perms(int pos, char current) {
    map<char, ll> already;
    ll j=0;
    ll soma=0;

    while(ranking[j]!=current) {
        ll produto=1;
        int n_elements=0;
        char counters[26] = {0};

        for(int i=pos+1; i<ranking.size(); i++) {
            counters[ranking[i]-'a']++;
            n_elements++;
        }
        
        // Fatorial
        for(int i=n_elements; i>=1; i--) {
            produto *= i;

            // Divisão
            for(int j=0; j<26; j++) {
                if(i==counters[j]) {
                    produto /= counters[j];
                    counters[j]--;
                }
            }
        }

        if(already.find(ranking[j])==already.end())
            soma += produto;
            
        already[ranking[j]] = produto;

        j++;
    }
    return soma;
}

int main() {
    string s;
    getline(cin, s);
    int n = s.length();

    string ordem = s;
    sort(ordem.begin(), ordem.end());

    for(int i=0; i<n; i++) {
        ranking.push_back(ordem[i]);        
    }

    // for(int i=0; i<n; i++) {
    //     cout << (i+1) << " " << ranking[i] << '\n';        
    // }
    ll soma=0;
    for(ll i=0; i<n; i++) {
        ll result = n_perms(i, s[i]);
        cout << result << '\n';
        soma += result;
    }

    cout << soma << '\n';
}