#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, m;
        string s, ans="";
        cin >> n >> k >> m;
        cin.ignore(1, '\n');
        cin >> s;

        bool found[k];
        memset(found, false, sizeof(found));
        int count=0;
        
        for(char c: s)
        {
            if(ans.size()==n)
                break;
            
            count += (!found[c-'a']); // Checa se é a primeira vez vendo a aquela letra nessa sequência e adiciona ao contador
            found[c-'a'] = true;

            // Se foram encontrados todos os caracteres naquela sequência,
            // então renicie o contador e a array
            if(count==k)
            {
                memset(found, false, sizeof(found));
                count = 0;
                // Construir o caso contra de maneira gulosa, ou seja
                // escolhe o caractere com o índice mais alto dentre as primeiras letras do alfabeto
                ans += c;
            }
        }

        if(ans.size()==n)
            cout << "YES\n";
        else
        {
            cout << "NO\n";
            for(int i=0; i<k; i++)
            {
                if(!found[i])
                {
                    while(ans.size()<n)
                    {
                        ans += (char)('a'+i);
                    }
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}