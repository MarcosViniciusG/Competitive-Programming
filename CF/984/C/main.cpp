#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t, q, j, v;
    string s;
    cin >> t;
    while(t--) {
        cin.ignore(1, '\n');
        getline(cin, s);

        vector<pair<string, bool>> prefixes;
        ll yes_count=0;

        for(int i=0; (i+3)<s.size(); i++) {
            string sub = s.substr(i, 4);
            bool is=(sub=="1100");
            yes_count+=is;
            prefixes.push_back(make_pair(sub, is));
        }

        // for(auto par: prefixes)
        //     cout << par.first << ' ' << par.second << '\n';

        // cout << yes_count << '\n';

        cin >> q;
        for(int i=0; i<q; i++) {
            cin >> j >> v;
            j--;

            int appears=min(int(prefixes.size()-1), j);
            // cout << appears << '\n';
            for(int k=appears, w=(j-appears); k>=max(0,(j-3)) && (w<4); k--, w++) {
                prefixes[k].first[w] = char(v+'0');
                // cout << prefixes[k].first << '\n';

                bool is=(prefixes[k].first=="1100");
                if(is && (!prefixes[k].second)) {
                    prefixes[k].second=true;
                    yes_count++;
                }
                
                if((!is) && (prefixes[k].second)) {
                    prefixes[k].second=false;
                    yes_count--;
                }
            }

            if(yes_count)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }


    return 0;
}