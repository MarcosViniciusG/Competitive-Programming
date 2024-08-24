#include <bits/stdc++.h>

using namespace std;

bool islower(char c) {
    return (c >= 'a' && c<= 'z');
}

int main() {
    string s;
    getline(cin, s);

    int nl=0;
    int nu=0;

    string l="";
    string u="";
    for(auto c: s) {
        if(islower(c)) {
            nl++;
            l += c;
            u += toupper(c);
        }
        else {
            nu++;
            l += tolower(c);
            u += c;
        }
    }

    if(nl > nu) 
        cout << l << endl;
    else
        cout << u << endl;

    return 0;
}