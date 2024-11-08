#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    int t, a1, a2, b1, b2;
    cin >> t;

    while(t--) {
        cin >> a1 >> a2 >> b1 >> b2;
        int ways=0;
        int a[2] = {a1, a2};
        int b[2] = {b1, b2};

        int ap[2] = {0, 1};
        int bp[2] = {0, 1};

        do
        {
            do
            {
                int vsu=0;
                int vsl=0;
                for(int i=0; i<2; i++) {
                    if(a[ap[i]] > b[bp[i]])
                        vsu++;
                    else if(a[ap[i]] < b[bp[i]])
                        vsl++;
                }

                if(vsu > vsl) ways++;

            } while (next_permutation(bp, bp+2));
            
        } while (next_permutation(ap, ap+2));
        

        cout << ways << endl;
    }

    return 0;
}