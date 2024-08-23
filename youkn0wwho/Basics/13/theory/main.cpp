#include <bits/stdc++.h>

using namespace std;

string bin_rep(int n) {
    string rep="";
    for(int i=7; i>=0; i--) {
        if((n & (1 << i)) != 0)
            rep += '1';
        else
            rep += '0';
    }

    return rep;
}

int main() {
    int a, b;
    cin >> a >> b;

    if(a >= (1 << 8) && b >= (1 << 8)) {
        cout << "ONLY INTEGERS BELOW 256 ARE ACCEPTED\n";
        return 1;
    }

    cout << "a (decimal) = " << a << endl;
    cout << "b (decimal) = " << b << endl;

    cout << "a (binary) = " << bin_rep(a) << endl;

    cout << "b (binary) = " << bin_rep(b) << endl;

    cout << "AND (&) = " << (a & b) << endl;
    cout << "  " << bin_rep(a) << " (a)" << endl;
    cout << "& " << bin_rep(b) << " (b)" << endl;
    cout << "  --------" << endl;
    cout << "  " << bin_rep(a & b) << endl;

    cout << "OR  (|) = " << (a | b) << endl;
    cout << "  " << bin_rep(a) << " (a)" << endl;
    cout << "| " << bin_rep(b) << " (b)" << endl;
    cout << "  --------" << endl;
    cout << "  " << bin_rep(a | b) << endl;

    cout << "XOR (^) = " << (a ^ b) << endl;
    cout << "  " << bin_rep(a) << " (a)" << endl;
    cout << "^ " << bin_rep(b) << " (b)" << endl;
    cout << "  --------" << endl;
    cout << "  " << bin_rep(a ^ b) << endl;

    cout << "NOT (~) = " << (~a) << endl;

    // a / (2^i)
    cout << "SHIFT RIGHT (in bits)" << endl;
    for(int i=0; i<4; i++)
        cout << a << " >> " << i << " = " << (a >> i) << endl;

    // a * (2^i)
    cout << "SHIFT LEFT (in bits)" << endl;
    for(int i=0; i<4; i++)
        cout << a << " << " << i << " = " << (a << i) << endl;
}