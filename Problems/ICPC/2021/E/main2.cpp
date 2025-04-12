#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, D;
    cin >> n;

    queue<int> n0, n1;

    for(int i = 0; i < n; i++)
    {
        int t, d;
        cin >> t >> d;

        if(d==0) n0.push(t);
        else n1.push(t);

        if(i == 0) D = d;
    }

    int save;

    if(D==0)
    {
        save = n0.front()+10;
        n0.pop();
    }
    else
    {
        save = n1.front()+10;
        n1.pop();
    } 

    bool changed = false, first = true;

    while(!n0.empty() || !n1.empty())
    {
        if(D == 0)
        {
            if(n0.front() <= save && !n0.empty())
            {
                if(!changed && first)
                {
                    save = n0.front()+10;
                    n0.pop();
                    first = false;
                }
                else if(!changed) n0.pop();
                else {
                    if(n1.front() > save) save = save + 10;
                    n0.pop();
                }
            }
            else if(!n1.empty())
            {
                n1.pop();
                save += 10;
                changed = true;
                first = true;
                D=1;
            }
            else {save = n0.front()+10;n0.pop();}
        }
        else
        {
            if(n1.front() <= save && !n1.empty())
            {
                if(!changed && first)
                {
                    save = n1.front()+10;
                    n1.pop();
                    first = false;
                }
                else if(!changed) n1.pop();
                else{
                    if(n1.front() > save)save += 10;
                    n1.pop();
                }
            }
            else if(!n0.empty())
            {
                n0.pop();
                save += 10;
                changed = true;
                first = true;
                D=0;
            }
            else {save = n1.front()+10;n1.pop();}
        }
    }
    cout << save << '\n';
}