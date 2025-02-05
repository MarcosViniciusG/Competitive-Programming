#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll st[2000][2000];
char ps[2000][2000];

string edit_operations(const string&s, const string& t)
{
    const ll c_i=1, c_r=1, c_s=1; // Costs
    ll m = s.length(), n = t.length();

    for(ll i=0; i<=m; i++) {
        st[i][0] = i*c_r;
        ps[i][0] = 'r';
    }

    for(ll j=1; j<=n; j++) {
        st[0][j] = j*c_i;
        ps[0][j] = 'i';
    }

    for(ll i=1; i<= m; i++) {
        for(ll j=1; j<= n; j++) {
            ll insertion = st[i][j-1] + c_i;
            ll deletion = st[i-1][j] + c_r;
            ll change = st[i-1][j-1] + c_s*(s[i-1]==t[j-1] ? ll(0) : ll(1));

            st[i][j] = min({insertion, deletion, change});

            ps[i][j] = (insertion <= deletion && insertion <=change) ? 
                'i' : (deletion <= change ? 'r' : 's');
        }
    }

    ll i=m, j=n;
    ostringstream os;

    while(i || j) {
        switch(ps[i][j]) {
            case 'i':
                os << t[j-1];
                j--;
                break;
            case 'r':
                os << '-';
                i--;
                break;
            case 's':
                if(s[i-1] == t[j-1])
                    os << '=';
                else
                    os << "]" << t[j-1] << ">-" << s[i-1] << "[";
            i--; j--;
        }
    }

    auto ops = os.str();
    reverse(ops.begin(), ops.end());

    return ops;
}

signed main() {
    string a, b;
    cin >> a >> b;
    cout << edit_operations(a, b) << '\n';

    return 0;
}