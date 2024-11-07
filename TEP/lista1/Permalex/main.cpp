#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<char> ranking;
ll n_perms(int pos, char current) {
    ll produto=1;
    int n_elements=0;
    int n_repeats=0;
    set<char> st;


    for(int i=pos+1; i<ranking.size(); i++) {
        if(st.find(ranking[i])!=st.end())
            n_repeats++;
        else
            st.insert(ranking[i]);

        n_elements++;
    }

    for(int i=n_elements; i>=1; i--) {
        produto *= n_elements;
        if(n_elements==n_repeats) {
            produto /= n_repeats;
            n_repeats--;
        }
    }
}

int main() {
    string s;
    getline(cin, s);
    int n = s.length();
    int countx=0;

    string ordem = s;
    sort(ordem.begin(), ordem.end());

    for(int i=0; i<n; i++) {
        ranking.push_back(ordem[i]);        
    }

    for(int i=0; i<n; i++) {
        cout << (i+1) << " " << ranking[i] << '\n';        
    }

    cout << (countx+1) << '\n';
}