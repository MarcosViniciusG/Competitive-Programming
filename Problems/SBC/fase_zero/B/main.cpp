#include <bits/stdc++.h>
#define INF 10000000

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

class Graph {
    ll V; 
    list<pll >* adj;

public:
    Graph(int V); 

    void addEdge(int u, int v, int w);

    vector<ll> shortestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pll>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

vector<ll> Graph::shortestPath(int src)
{
    priority_queue<pll, vector<pll>, greater<pll> >
        pq;

    vector<int> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        list<pll>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {

            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    vector<ll> times;
    for (int i = 0; i < V; ++i)
    {
        times.push_back(dist[i]);
    }
    return times;
}

int main()
{
    ll N, M, K, U, V, C, i, j;
    cin >> N >> M >> K;
    Graph g(N);
    
    for(i=0; i<M; i++)
    {
        cin >> U >> V >> C;
        g.addEdge(U-1, V-1, C);
    }
    vector<ll> shortests = g.shortestPath(0);
    sort(shortests.begin(), shortests.end());

    cout << shortests[K-1] << endl;

    return 0;
}