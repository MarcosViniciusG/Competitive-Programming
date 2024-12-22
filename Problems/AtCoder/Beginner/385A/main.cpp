#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;

    int soma = a + b + c;
    int menor1;
    int menor2;
    if(a <= b && a <= c)
        menor1 = a;
    else if(b <= a && b <= c)
        menor1 = b;
    else if(c <= a && c <= b)
        menor1 = c;
    
    if(a > menor1 && (a <= b || a <= c))
        menor2=a;
    else if(b > menor1 && (b <= a || b <= c))
        menor2 = b;
    else if(c > menor1 && (c <= a || c<=b))
        menor2 = c;
    else
        menor2 = a;
    
    ll menor3 = max({a, b, c});

    bool can = (menor1 + menor2 == menor3) || (menor1==menor2 && menor2==menor3);

    cout << (can ? "Yes" : "No") << '\n';

    return 0;
}