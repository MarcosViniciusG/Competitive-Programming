#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string n;
    ll m;
    getline(cin, n);

    int s = n.length();
    if(s%2!=0)
        s++;

    string revperm="";
    for(int i=0; i<s; i++) {
        if(i >= (s/2)) {
            revperm += '4';
        }
        else {
            revperm += '7';
        }
    }

    bool found = false;
    if(stol(n) > stol(revperm)) {
        found = true;
        s+=2;
    }

    string perm="";
    for(int i=0; i<s; i++) {
        if(i >= (s/2)) {
            perm += '7';
        }
        else {
            perm += '4';
        }
    }
    
    if(found) {
        cout << perm << endl;
        return 0;
    }

    do
    {
        if(stol(perm) >= stol(n)) {
            cout << perm << endl;
            break;
        }
    } while (next_permutation(perm.begin(), perm.end()));
    

    return 0;
}