#include <bits/stdc++.h>

using namespace std;

int sum_up_to_n(int n) {
    if(n==1)
        return 1;
    else
        return n + (sum_up_to_n(n-1));

}

int main() {    
    int n;
    cin >> n;
    
    cout << sum_up_to_n(n) << endl;

    return 0;
}