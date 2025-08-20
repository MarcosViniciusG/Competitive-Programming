#include <bits/stdc++.h>

using namespace std;

signed main() {
    int x, n;
    cin >> x >> n;

    set<int> st;
    st.insert(0);
    st.insert(x);
    int xi;
    int ans=x;
    int l=0;
    int r=x;
    for(int i=0; i<n; i++) {
        cin >> xi;
        st.insert(xi);
        auto it = st.find(xi);
        auto nex = st.upper_bound(xi);
        it--;
        if(*(it)==l && *(nex)==r) {
            int dis1 = abs(xi-l);
            int dis2 = abs(r-xi);
            if(dis1 > dis2) {
                ans = dis1;
                r = xi;
            }
            else {
                ans = dis2;
                l = xi;
            }
        } 
        cout << ans << ' ';
    }
    cout << '\n';

    return 0;
}