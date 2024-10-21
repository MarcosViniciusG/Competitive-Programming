#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;

int main() {
    string S, T;
    cin >> S >> T;

    bool can = false;
    for(int c=1; c < S.length(); c++) {
        for(int w = c; w < S.length(); w++) {
            string n = "";
            for(int i=0; i< S.length(); i+= w) {
                if((i+c-1) < S.length())
                    n += S[i+c-1]; 
            }

            if(T == n)
                can = true;
        }
    }

    if(!can)
        cout << "No\n";
    else  
        cout << "Yes\n";

    return 0;
}