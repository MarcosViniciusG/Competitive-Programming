#include <bits/stdc++.h>

using namespace std;
vector<int> generator(int N, int a, int b)
{
    int i;
    vector<int> v;
    for(i = a; i<=N; i+=a) v.push_back(i);

    for(i = b; i<=N; i+=b)
    {   
        if(i % a) v.push_back(i);
    }

    return v;
}

int main()
{
    int N,  a,  b;
    cin >> N >> a >> b;
    vector<int> v = generator(N, a, b);
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
    return 0;
}