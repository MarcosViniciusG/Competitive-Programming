#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll A, B, X, Y, i, count_A=0, count_B=0;
    set<ll> Alice;
    set<ll> Beatriz;
    cin >> A >> B;
    for(i=0; i<A; i++)
    {
        cin >> X;
        Alice.insert(X);
    }

    for(i=0; i<B; i++)
    {
        cin >> Y;
        Beatriz.insert(Y);
    }

    auto ptr = Alice.begin();
    while(ptr!=Alice.end())
    {
        if(Beatriz.find(*ptr)==Beatriz.end()) count_A++;
        //else cout << "Repetida: " << *ptr << endl;
        ptr++;
    }

    ptr = Beatriz.begin();
    while(ptr!=Beatriz.end())
    {
        if(Alice.find(*ptr)==Alice.end()) count_B++;
        //else cout << "Repetida: " << *ptr << endl;
        ptr++;
    }


    cout << min(count_A, count_B) << endl;
    return 0;
}