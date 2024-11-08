#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    ll bill;

    ll diff;

    // 0:100 1:50 2:25
    ll bills_qnt[3] = {0};

    bool can = true;
    for(ll i=0; i<n; i++) {
        cin >> bill;

        diff = bill - 25;

        if(diff==75) {
            if(bills_qnt[1]>=1 && bills_qnt[2]>=1) {
                bills_qnt[1]--;
                bills_qnt[2]--;
            }
            else if(bills_qnt[2]>=3)
                bills_qnt[2] -= 3;
            else
                can = false;
        }
        else if(diff==25) {
            if(bills_qnt[2]>=1)
                bills_qnt[2]--;
            else
                can = false;
        }

        if(bill==100)
            bills_qnt[0]++;
        else if(bill==50)
            bills_qnt[1]++;
        else if (bill==25)
            bills_qnt[2]++;
    }

    if(can)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}