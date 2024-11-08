#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll t, n, m, k, a, b, counter, exceed;

    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        set<ll> st;
        set<ll> st2;
        bool possible = true;
        counter=0;
        exceed=0;

        while(n--)
        {
            cin >> a;
            if(a <= k)
                st.insert(a);
        }

        if(st.size() < k/2)
            possible = false;
        else
            exceed = st.size() - k/2;

        while(m--)
        {
            cin >> b;
            if(b <= k && possible)
            {
                if(st.find(b)!=st.end())
                {
                    if(st2.find(b) == st2.end() && exceed > 0)
                    {
                        counter++;
                        exceed--;
                        st2.insert(b);
                    }
                }
                else
                {
                    if(st2.find(b) == st2.end())
                    {
                        counter++;
                        st2.insert(b);
                    }
                }

            }
        }

        if(counter>=k/2 && possible)
            cout << "YES\n";
        else
            cout << "NO\n";

    }


    return 0;
}