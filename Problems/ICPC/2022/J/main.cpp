#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n'
#define all(xs) xs.begin(), xs.end()
#define found(x, xs) (xs.find(x) != xs.end())
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define per(i, b, a) for (ll i = (b); i >= (a); --i)
#define x first
#define y second

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    pair<int,int> jm;
    vector<int> cards(10, 4);
    cards[9] = 16;

    int a, b;

    cin >> a >> b;
    if(a > 10) a = 10;
    if(b > 10) b = 10;
    cards[a-1]--;cards[b-1]--;
    jm.x = a + b;

    cin >> a >> b;
    if(a > 10) a = 10;
    if(b > 10) b = 10;
    cards[a-1]--;cards[b-1]--;
    jm.y = a + b;

    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if( a>10) a = 10;
        jm.x += a;
        jm.y += a;
        cards[a-1]--;
    }

    int ans = 0;

    if(jm.x > jm.y)
    {
        /* if(cards[24-jm.x-1] > 0) ans = 24-jm.x;
        else ans = -1; */
        int num = 24 - jm.x;
        while(num <= 10 && jm.y + num < 24)
        {
            if(cards[num - 1] > 0) {ans = num; break;}
            num++;
        }
        if(!ans) ans = -1;
    }
    else
    {
        if(cards[23-jm.y-1] > 0) ans = 23-jm.y;
        else ans = -1;
    }
    cout << ans << '\n';

    return 0;
}