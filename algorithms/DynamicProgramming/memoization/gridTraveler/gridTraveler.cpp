#include <bits/stdc++.h>

using namespace std;

int gridTraveler(int y, int x) {
    if(y==1 && x==1)
        return 1;
    if(y==0 || x==0)
        return 0;

    return gridTraveler(y-1, x) + gridTraveler(y, x-1);
}

int main() {

    cout << gridTraveler(2, 2) << endl;
    cout << gridTraveler(2, 3) << endl;
    cout << gridTraveler(3, 3) << endl;
    // > 1 second
    cout << gridTraveler(16, 16) << endl;
    
    return 0;
}