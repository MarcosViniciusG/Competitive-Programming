#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll           vector<ll>
#define pll           pair<ll, ll>
#define vpll          vector<pll>
#define endl '\n'
#define all(xs)       xs.begin(), xs.end()
#define found(x, xs) (xs.find(x) != xs.end())

signed main() {
    ll n, m;
    cin >> n >> m;
    vector<set<ll>> graph (n);
    ll a, b;
    for(ll i=0; i<m; i++) {
        cin >> a >> b;
        graph[a-1].insert(b-1);
        graph[b-1].insert(a-1);
    }

    if(n <= 10) {
        vll v;
        for(ll i=0; i<n; i++)
            v.push_back(i);

        bool can = true;
        do {
            can=true;
            for(ll i=0; i<n-1; i++) {
                if(graph[v[i]].count(v[i+1]) >= 1)
                    can = false;
            }

            if(can) 
                break;

        } while(next_permutation(all(v)));

        if(can) 
            for(auto e: v)
                cout << e+1 << ' ';
        else
            cout << -1;
    }
    else {
        set<ll> remaining;
        for(ll i=1; i<n; i++)
            remaining.insert(i);

        vll ans;
        ans.push_back(0);
        ll i=0;
        while(n > 10) {
            auto it=remaining.begin();
            bool found=false;
            while(!found) {
                ll el = *it;
                if(graph[ans[i]].count(el)==0) {
                    found = true;
                    remaining.erase(it);
                    ans.push_back(el);
                    break;
                }
                if(found)
                    break;
                it++;
            }

            i++;
            n--;
        }

        for(ll i=0; i<ll(ans.size()); i++)
            cout << ans[i] + 1 << ' ';

        vll aux;
        for(auto e: remaining)
            aux.push_back(e);

        sort(all(aux));
        bool can = true;
        do {
            can=true;
            for(ll i=0; i<9; i++) {
                if(i==0 && graph[aux[i]].count(ans[ll(ans.size())-1]) >= 1)
                    can = false;
                else if(graph[aux[i]].count(aux[i+1]) >= 1)
                    can = false;
            }

            if(can) 
                break;

        } while(next_permutation(all(aux)));

        for(auto e: aux)
            cout << e+1 << ' ';
    }


    cout << '\n';


    return 0;
}