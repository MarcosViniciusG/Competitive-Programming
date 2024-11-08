#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll A, B, C, a=0, b=0, c=0, fator1, fator2, fator3, i, j;
    cin >> A >> B >> C;

    for(i=1; i<=A && a==0 && b==0; i++)
    {
        if(A % i) continue;
        for(j=1; j*i <= A && a==0 && b==0; j++)
        {
            if(A%j) continue;
            if(j*i==A)
            {
                if(B%i==0)
                {
                    fator1 = i;
                    fator2 = j;
                    fator3 = B/i;
                }
                else if(B%j==0)
                {
                    fator1 = j;
                    fator2 = i;
                    fator3 = B/j;
                }
                else break;

                if(C==(fator3 * fator2))
                {
                    a = i;
                    b = j;
                    c = fator3;
                } 
            }
        }
    }

    cout << (a*4) + (b*4) + (c*4) << endl;
    return 0;
}