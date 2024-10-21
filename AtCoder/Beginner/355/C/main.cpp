#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, T;
    cin >> N >> T;

    int rc[N] = {0};
    int cc[N] = {0};
    int d1 = 0;
    int d2 = 0;

    int Ai;
    int achieved = -1;

    for(int i=0; i<T; i++) {
        cin >> Ai;
        Ai--;
        int r = Ai / N;
        int c = Ai % N;

        rc[r]++;
        cc[c]++;

        if(r==c)
            d1++;
        
        if(r==(N-c-1))
            d2++;

        if(achieved==(-1)) {
            if(rc[r]==N)
                achieved = i+1;
            else if(cc[c]==N)
                achieved = i+1;
            else if(d1==N)
                achieved = i+1;
            else if(d2==N)
                achieved = i+1;
        }
    }

    cout << achieved << endl;
    return 0;
}