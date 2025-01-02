#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

vll z(string s) {
    ll n = s.length(), L=0, R=0;
    vll zs(n, 0);
    for(ll i=1; i<n; i++) {
        if(i <= R)
            zs[i] = min(zs[i-L], R-i+1);
        
        while(zs[i] + i < n && s[zs[i]] == s[i + zs[i]]) {
            zs[i]++;
        }
        
        if(R < i + zs[i] - 1)
            L = i, R = i + zs[i] - 1;
    }

    return zs;
}

vll search(string s, string p, char delim='#') {
    string t {p + delim + s};
    vll zs = z(t);
    ll m=p.length();
    vll occ;

    for(ll i=0; i<ll(zs.size()); i++) {
        ll x = zs[i];
        if(x==m)
            occ.push_back(i-(m+1));
    }

    return occ;
}

vll z1(vll s) {
    ll n = s.size(), L=0, R=0;
    vll zs(n, 0);
    for(ll i=1; i<n; i++) {
        if(i <= R)
            zs[i] = min(zs[i-L], R-i+1);
        
        while(zs[i] + i < n && s[zs[i]] == s[i + zs[i]]) {
            zs[i]++;
        }
        
        if(R < i + zs[i] - 1)
            L = i, R = i + zs[i] - 1;
    }

    return zs;
}

set<ll> search1(vll s, vll p, ll delim=-1) {
    vll t;
    for(auto e: p)
        t.push_back(e);
    
    t.push_back(delim);

    for(auto e: s) 
        t.push_back(e);

    vll zs = z1(t);
    ll m=p.size();
    set<ll> occ;

    for(ll i=0; i<ll(zs.size()); i++) {
        ll x = zs[i];
        if(x==m)
            occ.insert(i-(m+1));
    }

    return occ;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    string li, ci;

    vector<pair<ll, char>> t;
    vector<pair<ll, char>> s;
    cin.ignore(1, '\n');
    char prev='#';
    for (ll i = 0; i < n; i++)
    {
        getline(cin, li, '-');
        if (i == n - 1)
            getline(cin, ci);
        else
            getline(cin, ci, ' ');
        
        if(ci[0]!=prev)
            t.push_back({stoll(li), ci[0]});
        else
            t[ll(t.size())-1].first += stoll(li);
        
        prev = ci[0];
    }

    prev='#';
    for (ll i = 0; i < m; i++)
    {
        getline(cin, li, '-');
        if (i == m - 1)
            getline(cin, ci);
        else
            getline(cin, ci, ' ');
        if(ci[0]!=prev)
            s.push_back({stoll(li), ci[0]});
        else
            s[ll(s.size())-1].first += stoll(li);
        
        prev = ci[0];
    }

    n = t.size();
    m = s.size();

    string ts="", ss="";
    vll tnumber, snumber, tmiddle, smiddle;
    ll j=0;
    for(ll i=0; i<n; i++, j++) {
        ts += t[i].second;
        tnumber.push_back(t[i].first);
        if(i!=0 && i!=n-1) 
            tmiddle.push_back(t[i].first);

        if(j < m) {
            ss += s[j].second;
            snumber.push_back(s[j].first);
            if(j!=0 && j!=m-1)
                smiddle.push_back(s[j].first);
        } 
    }

    for(j=j; j<m; j++) {
        ss+=s[j].second;
        snumber.push_back(s[j].first);
        if(j!=0 && j!=m-1)
            smiddle.push_back(s[j].first);
    }

    vll occ = search(ts, ss);

    ll ans = 0;
    if(m==1) {
        for(auto e: occ) {
            if(tnumber[e] >= snumber[0])
                ans += (tnumber[e] - snumber[0] + 1);
        }
    }
    else if(m==2) {
        for(auto e: occ) {
            if(tnumber[e] >= snumber[0] && tnumber[e+1] >= snumber[1])
                ans++;
        }
    }
    else {
        set<ll> occ1 = search1(tmiddle, smiddle);

        ll first_n = snumber[0];
        ll last_n = snumber[m-1];
        char first_char = ss[0];
        char last_char = ss[m-1];
        for(auto e: occ) {
            if(occ1.find(e)!=occ1.end()) {
                if(ts[e] == first_char && ts[e+m-1] == last_char && tnumber[e] >= first_n && tnumber[e+m-1] >= last_n)
                    ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}