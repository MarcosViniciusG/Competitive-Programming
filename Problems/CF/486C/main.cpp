#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    int n, p;
    cin >> n >> p;
    cin.ignore(1, '\n');

    string s;
    getline(cin, s);

    int dist[n/2];

    for(int i=0; i<(n/2); i++) {
        int j = n - i - 1;
        int path1, path2;
        if(s[i] >= s[j]) {
            path1 = (s[i] - s[j]); // Diminui s[i] até s[j]
            path2 = ('z' - s[i]) + (s[j] -'a') + 1;
        }  
        else {
            path1 = (s[j]-s[i]); // Diminui s[j] até s[i]
            path2 = ('z' - s[j]) + (s[i]-'a')+ 1;
        }
        // cout << path2 << '\n';
        dist[i] = min(path1, path2);
    }

    for(int i=0; i<(n/2); i++) {
        cout << dist[i] << ' ' << i << '\n';
    }

    cout << '\n';

    p--;
    if(n & 1) {
        if(p==(n/2))
            p = (n/2)-1;
    }
    p %= (n/2);
    cout << p << '\n';
    

    ll counter1=0;
    ll sim = 0;
    ll new_p=p;

    // Walk to right and change if necessary
    for(int i=p; i<(n/2); i++) {
        if(dist[i] > 0) {
            // cout << i << " " << dist[i] << " " << sim << '\n';
            counter1 += dist[i];
            counter1 += sim;
            new_p = i;
            sim = 0;
            dist[i] = 0;
        }
        sim++;
    }

    sim = 0;
    // Walk to left and change if necessary
    for(int i=new_p; i>=0; i--) {
        if(dist[i] > 0) {
            // cout << i << " " << dist[i] << " " << sim << '\n';
            counter1 += dist[i];
            counter1 += sim;
            new_p = i;
            sim = 0;
        }
        sim++;
    }
    
    cout << min(counter1, counter2) << '\n';

    return 0;
}