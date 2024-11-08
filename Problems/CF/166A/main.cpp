#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, n, pi, ti;
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    vector<pair<int, int>> teams;
    for(int i=0; i<n; i++) {
        cin >> pi >> ti;
        teams.push_back(make_pair(pi, ti));
    }

    //sort(teams.begin(), teams.end(), greater<pair<int, int>>());

    // Bubble sort
    for(int i=0; i<n; i++) {
        for(int j=0; j<(n-1); j++) {
            if(teams[j+1].first > teams[j].first || (
                (teams[j+1].first == teams[j].first) && teams[j+1].second < teams[j].second)) {
                    swap(teams[j], teams[j+1]);    
                } 
        }
    }


    // for(int i=0; i<n; i++) {
    //     if(i == k-1) {
    //         cout << "Escolhido: " << endl;
    //     }
    //     cout << teams[i].first << " " << teams[i].second << "\n";
    // }

    int co = 1;

    int i=k-1;
    while(i > 0 && (teams[i]==teams[i-1]))
    {
        // cout << teams[i].first << " " << teams[i].second << " " << teams[i-1].first << " " << teams[i-1].second <<  '\n';
        co++;
        i--;
    }

    i=k-1;
    while(i < (n-1) && (teams[i]==teams[i+1]))
    {
        // cout << teams[i].first << " " << teams[i].second << " " << teams[i+1].first << " " << teams[i+1].second <<  '\n';
        co++;
        i++;
    }
    
    cout << co << '\n';
    return 0;
}