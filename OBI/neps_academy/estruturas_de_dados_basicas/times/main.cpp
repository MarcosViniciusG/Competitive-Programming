#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    int N, T;
    cin >> N >> T;
    string nome;
    ll H;

    priority_queue<pair<ll, string>, vector<pair<ll, string>>> pq;
    for(int i=0; i<N; i++)
    {
        cin >> nome >> H;
        pair<ll, string> p {H, nome};
        pq.push(p);
    }

    // while (pq.size() != 0)
    // {
    //     cout << "Habilidade: " << pq.top().first << " " << "Nome: " << pq.top().second << endl;
    //     pq.pop();
    // }

    vector<priority_queue<string, vector<string>, greater<string>>> times (T);
    int count = 0;
    while (pq.size() != 0)
    {
        times[count % T].push(pq.top().second);
        pq.pop();
        count++;
    }

    for(int i=0; i<T; i++)
    {
        cout << "Time " << i+1 << endl;
        while(times[i].size() != 0)
        {
            cout << times[i].top() << endl;
            times[i].pop();
        }
        if(i!=T-1) cout << endl;
    }
    
    return 0;
}