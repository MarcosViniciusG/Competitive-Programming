#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, p_i, av, counter=0, soma;
    vector<int> petals;

    cin >> n;
    while(n--)
    {
        cin >> p_i;
        petals.push_back(p_i);
    }

    for(int i=0; i<petals.size(); i++)
    {
        soma = 0;
        for(int j=i; j<petals.size(); j++)
        {
            soma += petals[j];

            if(soma % (j-i+1)==0)
                av = soma / (j-i + 1);
            else
                av = 0;
            
            bool find = false;
            for(int k=i; k<=j && av != 0 && !find; k++)
            {
                if(petals[k]==av) 
                {
                    // cout << petals[k] << " " << av << " " << i << " " << j << endl;
                    counter++;
                    find = true;
                }
            }
        }
    }

    cout << counter << endl;
    return 0;
}