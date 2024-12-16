#include <bits/stdc++.h>

using namespace std;

signed main() {
    string flags, firstp, secondp;
    getline(cin, flags);
    getline(cin, firstp);
    getline(cin, secondp); 

    bool forward=false;
    bool backward=false;

    int n1 = flags.size();
    int n2 = firstp.size();
    int n3 = secondp.size();

    bool swi=false;
    for(int i=0; i<n1 && !forward; i++) {
        if(!swi && i<=(n1-n2)) {
            swi = flags.substr(i, n2)==firstp;
            if(swi)
                i += n2-1;
        }
        else if(swi && i <=(n1-n3)) {
            forward = flags.substr(i, n3)==secondp;
        }
    }

    reverse(flags.begin(), flags.end());
    swi = false;
    for(int i=0; i<n1 && !backward; i++) {
        if(!swi && i<=(n1-n2)) {
            swi = flags.substr(i, n2)==firstp;
            if(swi) {
                i += n2-1;
            }
        }
        else if(swi && i <=(n1-n3)) {
            backward = flags.substr(i, n3)==secondp;
        }
    }

    if(forward && backward)
        cout << "both";
    else if(forward)
        cout << "forward";
    else if(backward)
        cout << "backward";
    else
        cout << "fantasy";
    
    cout << '\n';

    return 0;
}