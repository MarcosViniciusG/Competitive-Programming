#include <bits/stdc++.h>

using namespace std;

int to_int(char c) {
    return (c - '0');
}

signed main() {
    string inteiro, decimal;
    getline(cin, inteiro, '.');
    getline(cin, decimal);

    int n = inteiro.length(), m = decimal.length();
    if(inteiro[n-1]!='9') {
        if(to_int(decimal[0]) < 5)
            cout << inteiro << '\n';
        else {
            inteiro[n-1] = (to_int(inteiro[n-1]) + 1) + '0';
            cout << inteiro << '\n';
        }
    }
    else
        cout << "GOTO Vasilisa.\n";

    return 0;
}