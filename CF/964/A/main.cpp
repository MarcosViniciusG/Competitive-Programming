#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    int t;
    string n;
    cin >> t;
    cin.ignore(1, '\n');
    while(t--) {
        int sum = 0;
        getline(cin , n);
        
        for(auto c: n) {
            sum += (c - '0');
        }
        cout << sum << endl;
    }
    return 0;
}