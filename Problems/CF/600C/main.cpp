#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    int n=s.length();

    int hist[26] = {0};
    for(auto c: s)
        hist[c-'a']++;
    
    priority_queue<int> odds;
    for(int i=25; i>=0; i--) {
        if(hist[i] & 1) {
            odds.push(i);
        }
    }

    // Histogram before
    // for(int i=0; i<26; i++)
    //     cout << hist[i] << ' ';
    // cout << '\n';

    for(int i=0; i<26; i++) {
        if((hist[i] & 1) && (!odds.empty())) {
            hist[i]++;
            hist[odds.top()]--;
            odds.pop();
        }
    }

    // Histogram after
    // for(int i=0; i<26; i++)
    //     cout << hist[i] << ' ';
    // cout << '\n';

    int last_odd=-1;
    if(n & 1) {
        for(int i=0; i<26; i++)
            if(hist[i] & 1) {
                last_odd = i;
                break;
            }
    }

    string ans="";
    for(int i=0; i<26; i++) {
        int reps = (hist[i]/2);
        for(int j=0; j<reps; j++) {
            ans += char(i + 'a');
        }
    }

    if(last_odd!=-1) {
        ans += char(last_odd + 'a');
    }

    for(int i=25; i>=0; i--) {
        for(int j=0; j<(hist[i]/2); j++) {
            ans += char(i + 'a');
        }
    }

    cout << ans << '\n';

    return 0;
}