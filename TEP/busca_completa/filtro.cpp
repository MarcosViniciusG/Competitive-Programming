#include <bits/stdc++.h>

using namespace std;
vector<int> filter(int N, int a, int b)
{
    vector<int> multiplos;
    for(int i=1; i <= N; i++)
    {
        if(i % a==0 || i % b==0)
        {
            multiplos.push_back(i);
        }
    }

    return multiplos;
}

int main()
{
    int N, a, b;
    cin >> N >> a >> b;
    vector<int> multiplos = filter(N, a, b);
    for(int i=0; i<multiplos.size(); i++)
    {
        cout << multiplos[i] << " ";
    }

    cout << endl;
}