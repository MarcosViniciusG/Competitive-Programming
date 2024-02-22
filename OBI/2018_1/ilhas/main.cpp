#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
ll oo = 1e7;
pair<vll, vi> dijkstra(const vector<vector<pll>> &g, int n,
                       int s) {
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  vll dist(n, oo);
  vi p(n, -1);
  pq.emplace(0, s);
  dist[s] = 0;
  while (!pq.empty()) {
    auto [d1, v] = pq.top();
    pq.pop();
    if (dist[v] < d1) continue;

    for (auto [d2, u] : g[v]) {
      if (dist[u] > d1 + d2) {
        dist[u] = d1 + d2;
        p[u] = v;
        pq.emplace(dist[u], u);
      }
    }
  }
  return {dist, p};
}

int main()
{
    int N, M, U, V, P;
    cin >> N >> M;

    vector<vector<pll>> grafo(N);

    for(int i=0; i<M; i++)
    {
        cin >> U >> V >> P;

        pll par = {P, V-1};
        grafo[U-1].push_back(par);
        par = {P, U-1};
        grafo[V-1].push_back(par);
    }

    // for(int i=0; i<N; i++)
    // {

    //     for(auto par: grafo[i])
    //     {
    //         cout << "Primeira ilha: " << i+1 << " Segunda ilha: " << par.second+1 << " Ping: " << par.first << endl; 
    //     }
    // }

    int S;
    cin >> S;

    pair<vll, vi> retorno = dijkstra(grafo, N, S-1);
    // for(auto dist: retorno.first)
    // {
    //     cout << dist << endl;
    // }

    ll maior=-1, menor=oo;

    for(auto dist: retorno.first)
    {
        if(dist==0) continue;
        maior = max(dist, maior);
        menor = min(dist, menor);
    }

    cout << maior - menor << endl;

    return 0;
}