#include <bits/stdc++.h>

using namespace std;
int solve(long long int n)
{
    vector<int> xs {6, 8, 4, 2};
    int ld = xs[n%4];
    if (n==0) return 1;
    else return ld; 
}

int main()
{
    long long int n;
    cin >> n;
    cout << solve(n) << endl;
}