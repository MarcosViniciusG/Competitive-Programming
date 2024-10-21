#include <bits/stdc++.h>

using namespace std;

// Any permutation can be divided into some number of cycles
void solve(int n, vector<int> p, string s) {
    // Array to store the number of the cycle the ith element is located
    int cycle_location[n];
    
    // Vector to store the number of blacks in the ith cycle
    vector<int> cycle_number;
    
    // The number of the cycle
    int cycle_n=0;

    // Vector to see if a element has already been visited
    bool visited[n] = {0};

    for(int i=0; i<n; i++) {
        if(visited[i]) 
            continue;
        
        int n_blacks=0;

        int cycle_start=i;
        int next = p[i]-1;

        visited[cycle_start] = 1;

        cycle_location[cycle_start] = cycle_n;

        if(s[cycle_start]=='0')
            n_blacks++;

        while(cycle_start!=next) {
            if(s[next]=='0')
                n_blacks++;

            cycle_location[next] = cycle_n;
            next = p[next] - 1;
        }

        cycle_number.push_back(n_blacks);
        cycle_n++;
    }

    for(int i=0; i<n; i++)
        cout << cycle_number[cycle_location[i]] << " ";

    cout << endl;
}

int main() {
    int t, n;
    cin >> t;

    int pi;
    string s;
    while(t--) {
        cin >> n;
        vector<int> p;
        for(int i=0; i<n; i++) {
            cin >> pi;
            p.push_back(pi);
        }
        cin.ignore(1, '\n');

        getline(cin, s);
        solve(n, p, s);
    }

    return 0;
}