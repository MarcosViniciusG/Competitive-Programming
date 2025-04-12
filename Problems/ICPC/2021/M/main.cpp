#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
#define x first 
#define y second 
#define all(xs) xs.begin(), xs.end()

vector<set<ll>> graph (100001);
queue<ll> deaths;
set<ll> removed;
ll curr=1;

signed main()
{
    int n;
    cin >> n;

    ll a, b;
    ll prox=2;
    set<ll> removed;
    for(ll i=0; i<n; i++) {
        cin >> a >> b;
        if(a==1) {
            graph[b].insert(prox);
            prox++;
        }
        else
            deaths.push(b);
    }

    stack<ll> st;
    st.push(1);
    while(!deaths.empty()) {
        ll death = deaths.front(); deaths.pop();
        removed.insert(death); 
        while(removed.find(st.top()) != removed.end()) {
            if(!graph[st.top()].empty()) {
                ll nex = *(graph[st.top()].begin());
                graph[st.top()].erase(graph[st.top()].begin());
                st.push(nex);
                continue;
            }
            
            st.pop();
        }
        cout << st.top() << '\n';
    }
}