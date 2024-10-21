#include <bits/stdc++.h>

using namespace std;

void subsets(vector<int> a) {
    int n = a.size();

    for(int bit=0; bit <(1 << n); bit++) {
        vector<int> subset;

        for(int i=0; i<n; i++) {
            if((bit & (1 << i)) !=0)
                subset.push_back(a[i]);
        }
    }
} 