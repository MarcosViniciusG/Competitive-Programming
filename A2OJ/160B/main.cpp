#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> first;
    vector<int> second;

    string s;
    cin >> s;

    for(int i=0; i<n; i++) {
        first.push_back(s[i]);
        second.push_back(s[i+n]);
    }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    bool can1=true;
    for(int i=0; i<n; i++) {
        if(first[i] >= second[i])
            can1 = false;
    }

    bool can2=true;
    for(int i=0; i<n; i++) {
        if(first[i] <= second[i])
            can2 = false;
    }

    if(can1 || can2)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}