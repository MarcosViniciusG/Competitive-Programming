#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

signed main() {
    int n;
    cin >> n;
    multiset<int> st;
    int xi;
    for(int i=0; i<n; i++) {
        cin >> xi;
        auto it = st.upper_bound(xi);
        if(it==st.end())
            st.insert(xi);
        else {
            st.erase(it);
            st.insert(xi);
        }
    }

    cout << st.size() << '\n';

    return 0;
}