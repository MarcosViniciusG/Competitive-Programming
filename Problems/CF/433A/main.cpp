#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, w;
    cin >> n;
    
    int w100=0;
    int w200=0;
    int total = 0;
    for(int i=0; i<n; i++)
    {
        cin >> w;
        if(w==100)
            w100++;
        else
            w200++;
        
        total += w;
    }

    int half = total/2;

    int soma=0;
    for(int i=0; i<w200 && (soma < half); i++)
        soma+= 200;

    if(soma > half)
        soma -= 200;

    int s100=0;
    for(int i=0; i<w100 && (soma < half); i++)
    {
        soma+=100;
    }    

    if(soma == half)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}